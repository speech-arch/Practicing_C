##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=UOCCovid19Vaccine
ConfigurationName      :=Debug
WorkspacePath          :=/home/uoc/Pictures/UOCProgrammeEC
ProjectPath            :=/home/uoc/Pictures/UOCProgrammeEC/UOCCovid19Vaccine
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=uoc
Date                   :=22/03/21
CodeLitePath           :=/home/uoc/.codelite
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../lib/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="UOCCovid19Vaccine.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)./include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_commons.c$(ObjectSuffix) $(IntermediateDirectory)/src_vaccine.c$(ObjectSuffix) $(IntermediateDirectory)/src_country.c$(ObjectSuffix) $(IntermediateDirectory)/src_developer.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "/home/uoc/Pictures/UOCProgrammeEC/.build-debug"
	@echo rebuilt > "/home/uoc/Pictures/UOCProgrammeEC/.build-debug/UOCCovid19Vaccine"

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_commons.c$(ObjectSuffix): src/commons.c $(IntermediateDirectory)/src_commons.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Pictures/UOCProgrammeEC/UOCCovid19Vaccine/src/commons.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_commons.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_commons.c$(DependSuffix): src/commons.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_commons.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_commons.c$(DependSuffix) -MM src/commons.c

$(IntermediateDirectory)/src_commons.c$(PreprocessSuffix): src/commons.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_commons.c$(PreprocessSuffix) src/commons.c

$(IntermediateDirectory)/src_vaccine.c$(ObjectSuffix): src/vaccine.c $(IntermediateDirectory)/src_vaccine.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Pictures/UOCProgrammeEC/UOCCovid19Vaccine/src/vaccine.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_vaccine.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_vaccine.c$(DependSuffix): src/vaccine.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_vaccine.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_vaccine.c$(DependSuffix) -MM src/vaccine.c

$(IntermediateDirectory)/src_vaccine.c$(PreprocessSuffix): src/vaccine.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_vaccine.c$(PreprocessSuffix) src/vaccine.c

$(IntermediateDirectory)/src_country.c$(ObjectSuffix): src/country.c $(IntermediateDirectory)/src_country.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Pictures/UOCProgrammeEC/UOCCovid19Vaccine/src/country.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_country.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_country.c$(DependSuffix): src/country.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_country.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_country.c$(DependSuffix) -MM src/country.c

$(IntermediateDirectory)/src_country.c$(PreprocessSuffix): src/country.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_country.c$(PreprocessSuffix) src/country.c

$(IntermediateDirectory)/src_developer.c$(ObjectSuffix): src/developer.c $(IntermediateDirectory)/src_developer.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/uoc/Pictures/UOCProgrammeEC/UOCCovid19Vaccine/src/developer.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_developer.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_developer.c$(DependSuffix): src/developer.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_developer.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_developer.c$(DependSuffix) -MM src/developer.c

$(IntermediateDirectory)/src_developer.c$(PreprocessSuffix): src/developer.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_developer.c$(PreprocessSuffix) src/developer.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


