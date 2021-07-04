#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <stdio.h>
#include "developer.h"

// **** Functions related to management of tDeveloper objects

// Initialize a developer object
tError developer_init(tDeveloper* dev, const char* name, tCountry* country, tVaccine* vaccine) {
    // PR1 EX3
	//check pre conditions
	assert(dev!=NULL);
	assert(name!=NULL);
	assert(country!=NULL);
	assert(vaccine!=NULL);
	// do allocation of memory
	dev->name=(char*)malloc((strlen(name) + 1) * sizeof(char));
		//check if allo memory allocation was done right
	if(dev->name==NULL){
		return ERR_MEMORY_ERROR;
	}
	// copy and do allocat memory for the next other field 
	strcpy(dev->name,name);
	dev->country=(tCountry*)malloc((strlen(country->name) + 1) * sizeof(tCountry));
	//check if allo memory allocation was done right
	if(dev->country==NULL){
		return ERR_MEMORY_ERROR;
	}
	country_init(dev->country,country->name,country->isEU);
     dev->vaccine=(tVaccine*)malloc((strlen(vaccine->name) + 1) * sizeof(tVaccine));
    if(dev->vaccine==NULL){
		return ERR_MEMORY_ERROR;
	}
	vaccine_init(dev->vaccine,vaccine->name,vaccine->vaccineTec,vaccine->vaccinePhase);
	vaccine_cpy(dev->vaccine,vaccine);
		 return OK;	
}
		
// Release memory used by developer object
void developer_free(tDeveloper* object) {
    // PR1 EX3
	assert(object!=NULL);
	
	if(object->name!=NULL){
		free(object->name);
		object->name=NULL;
	}
  
    
}

// Compare two developer objects
bool developer_equals(tDeveloper* dev1, tDeveloper* dev2) {
    //PR1 EX3
   assert(dev1 != NULL);
	assert(dev2 != NULL);
	
		//&& dev1->country==dev2->country &&dev1->vaccine==dev2->vaccine
	   if(strcmp(dev1->name, dev2->name)!=0){
		   return false;;
	   }
		
	   return true;
	    
}

// Copy the data of a developer to another developer
tError developer_cpy(tDeveloper* dest, tDeveloper* src) {
tCountry country;

  assert(dest != NULL);
 
	assert(src != NULL);
	 tError fail;


    // Just in case, free space used by destination object.
  developer_free(dest);

    // Initialize the element with the new data
  fail = developer_init(dest, src->name, src->country,src->vaccine);
  if(fail != OK)
     return fail;
   return OK;

}


// **** Functions related to management of tDeveloperTable objects

// Initialize the table of developers
void developerTable_init(tDeveloperTable* table) {
  // PR1 EX3
	assert(table != NULL);
	
	table->size = 0;
	
	 table->elements = NULL;
}

// Release the memory used by tDeveloperTable structure
void developerTable_free(tDeveloperTable* table) {
    // PR1 EX3  
	int i;

    assert(table != NULL);
      if(table->elements != NULL) {
        for(i = 0; i < table->size; i++) {
            developer_free(&table->elements[i]);
        }
        free(table->elements);
        table->elements = NULL;
        // As the table is now empty, assign the size to 0.
        table->size = 0;
    }
}

// Add a new developer to the table
tError developerTable_add(tDeveloperTable* table, tDeveloper* dev) {
    // PR1 EX3
	tDeveloper* temps;
	tCountry *country;
	int i;
	tError fail;
	assert(table!=NULL);
	assert(dev!=NULL);
	
	if(developerTable_find(table,dev)!=ERR_NOT_FOUND )
	return ERR_DUPLICATED;
	
	   if(table->size == 0) {  // Empty table
        // Since the table is empty, and we do not have any previous memory block,
        // we have to use malloc. The amount of memory we need is the number of
        // elements (will be 1) times the size of one element, which is computed
        // by sizeof(type). In this case the type is tCountry.
        temps = (tDeveloper*)malloc((table->size + 1) * sizeof(tDeveloper));

        // Check that the memory has been allocated
        if(temps == NULL) {
            // Error allocating or reallocating the memory
            return ERR_MEMORY_ERROR;
        } else {
            table->elements = temps;
            // set the table size to one
            table->size = 1;
        }
    } else { // table with elements
        // Since the table is not empty, we already have a memory block.
        // We need to modify the size of this block, using the realloc command.
        // The amount of memory we need is the number of elements times
        // the size of one element, which is computed by sizeof(type).
        // In this case the type is tCountry. We provide the previous block of memory.
        temps = (tDeveloper*)realloc(table->elements, (table->size + 1) * sizeof(tDeveloper));
        // Check that the memory has been allocated
        if(temps == NULL) {
            // Error allocating or reallocating the memory
            return ERR_MEMORY_ERROR;
        } else {
            table->elements = temps;
            // Increase the number of elements of the table
            table->size = table->size + 1;
        }
    }

    // Once we have the block of memory, which is an array of tCountry elements,
    // we initialize the new element (which is the last one). The last element
    // is " table->elements[table->size - 1] " (we start counting at 0)
    fail = developer_init(&(table->elements[table->size - 1]),dev->name, dev->country, dev->vaccine);
    if(fail != OK)
        return fail;

    return OK;
	
}

// Remove a developer from the table
tError developerTable_remove(tDeveloperTable* table, tDeveloper* dev) {
    // PR1 EX3
	tDeveloper* elementsAux;
    tError error;
	//check pre conditions
	assert(table != NULL);
    assert(dev != NULL);
	bool found;
	int i;
	  found = false;
	  // To remove an element of a table, we will move all elements after this element one position,
    // to fill the space of the removed element.
    for(i = 0; i < table->size; i++) {
		 // If the element has been found. Displace this element to the previous element
        // (will never happend for the first one). We use the ADDRESS of the previous element &(table->elements[i-1])
        // as destination, and ADDRESS of the current element &(table->elements[i]) as source.
        
        if(found) {
           
            if(developer_cpy(&(table->elements[i - 1]), &(table->elements[i])) == ERR_MEMORY_ERROR) {
              
                return ERR_MEMORY_ERROR;
            }
        } else
            if(developer_equals(&table->elements[i], dev)) {
                // The current element is the element we want to remove. Set found flag to true to start element movement.
                found = true;
            }
    }

    // Once removed the element, we need to modify the memory used by the table.
    if(found) {
        // If we are removing the last element, we will free
        // the last/remaining element in table / assign pointer
        // to NULL
        if(table->size <= 1) {
            developerTable_free(table);
        } else {
            developer_free(&table->elements[table->size - 1]);
            // Modify the used memory. As we are modifying a previously
            // allocated block, we need to use the realloc command.
            elementsAux = (tDeveloper*)realloc(table->elements, (table->size - 1) * sizeof(tDeveloper));

            // Check that the memory has been allocated
            if(elementsAux == NULL) {
                // Error allocating or reallocating the memory
                return ERR_MEMORY_ERROR;
            } else {
                table->elements = elementsAux;
                // Succesfully allocated, set new table size
                table->size = table->size - 1;
            }
        }
    } else {
        // If the element was not in the table, return an error.
        return ERR_NOT_FOUND;
    }

    return OK;
	
	
}

// Returns the number of tDeveloper that have an authorized vaccine in at least one country
int developerTable_num_authorized(tDeveloperTable* table) {
    // PR1 EX3
	int i ,counter;
	//initializetion of the variable
	 counter=0;
	//check pre conditions	
	assert(table!=NULL);

  // check if the size of the authorized in the table is greater
  // than zero the it increment the counter;
	if(table->size>0){
	for(i=0;i<table->size;i++){
		if(table->elements[i].vaccine->authCountries->size!=0){
			 counter++;
		}
	 }
	}
   return counter;
}

// Returns the position of the tDeveloper table with the vaccine that has more countries that
// authorize it, in case of a tie it would select the first one in the table.
int developerTable_most_popular(tDeveloperTable* table) {
    // PR1 EX3
	int counter, temps,i, index;
	counter =0;
	//check pre conditions
	assert(table!=NULL);
   //initializetion of variables 
	index=ERR_EMPTY_LIST;
	counter =0;
	//check and compere country_vaccine table size with maxim size record and later 
	//update the new maxim values
	if(table->size>0){
	for(i=0;i<table->size;i++){
		temps =table->elements[i].vaccine->authCountries->size;
		if(temps>counter){
		 counter=temps;
			index= i;
		}
	 }
   }
    return index;
}

// Given a tDeveloper find the position it occupies in the tDevelope table
int developerTable_find(tDeveloperTable* table, tDeveloper* dev) {
    // PR1 EX3

    int i;

    // Verify pre conditions
    assert(table != NULL);
    assert(dev != NULL);

    // Search over the table and return once we found the element.
  for(i = 0; i < table->size; i++) {
  
   if(developer_equals(&table->elements[i], dev)) {
            // Return the position of the element
            return i;
        }
   }
    // The element has not been found. Return ERR_NOT_FOUND.
    return ERR_NOT_FOUND;
}

// Get the size of the table
unsigned int developerTable_size(tDeveloperTable* table)  {
    // Verify pre conditions
    assert(table != NULL);

      //table->size=(table->size);

    // The size of the table is the number of elements. This value is stored in the "size" field.
    return table->size;
}

// Prints basic information from the tDeveloper table on the screen
void developerTable_print(tDeveloperTable* table) {
    int i;

    // Verify pre conditions
    assert(table != NULL);

    for(i = 0; i < table->size; i++) {
        developer_print(&table->elements[i]);
    }
    printf("\n");
}

// prints basic information from the tDeveloper on the screen
void developer_print(tDeveloper* dev) {
    // Verify pre conditions
    assert(dev != NULL);

    printf("%s %s %s\n", dev->name, dev->country->name, dev->vaccine->name);
}
