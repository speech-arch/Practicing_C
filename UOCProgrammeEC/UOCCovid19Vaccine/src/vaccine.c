#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "vaccine.h"

// Initialize a vaccine
tError vaccine_init(tVaccine* vac, const char* name, tVaccineTec tec, tVaccinePhase phase) {
    // PR1 EX2  
	//verification of preconditions
	assert(vac!=NULL);
	assert(name!=NULL);
	// do allocation of memory
	vac->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	//check if allo memory allocation was done right
	 if(vac->name == NULL) {
        return ERR_MEMORY_ERROR;
    }
	// copy and initialize the other fields 
	strcpy(vac->name,name);
	vac->vaccineTec=tec;
	vac->vaccinePhase=phase;
	vac->authCountries = (tCountryTable*)malloc(1* sizeof(tCountryTable));
	 if(vac->authCountries == NULL) {
        return ERR_MEMORY_ERROR;
	 }
		countryTable_init(vac->authCountries);

     return OK;
}
         

// Release memory used by a vaccine
void vaccine_free(tVaccine* vac) {
    // PR1 EX2
	//check pre conditions
	assert(vac!=NULL);
	// check and free memory
	countryTable_free(vac->authCountries);
     if(vac->name != NULL) {
        free(vac->name);
        vac->name = NULL;
    }
}

// Compare two vaccines
bool vaccine_equals(tVaccine* vac1, tVaccine* vac2) {
    // PR1 EX2
	//check pre conditions
	    assert(vac1 != NULL);
        assert(vac2 != NULL);
 if(strcmp(vac1->name, vac2->name) == 0){
	  // Countries are the same
	 return true;
 }
  // Countries are different
    return false;
}

// Copy a vaccine
tError vaccine_cpy(tVaccine* dest, tVaccine* src) {
    // PR1 EX2
		tError error;
	//check pre conditions
	assert(dest!=NULL);
	assert(src!=NULL);
	
//free space at destination
	vaccine_free(dest);
	// Initialize the element with the new data
	
    error=vaccine_init(dest,src->name,src->vaccineTec,src->vaccinePhase);
	if(error != OK) return error;
	
	error= countryTable_cpy(dest->authCountries,src->authCountries);
	if (error != OK) return error;
	
	return OK;
}

// Add an authorized country to a vaccine
tError vaccine_add_authorized_country(tVaccine* vac, tCountry* country) {
		countryTable_add(vac->authCountries, country);

    return OK;

	
	
}



