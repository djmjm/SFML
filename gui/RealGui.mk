##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=RealGui
ConfigurationName      :=Debug
WorkspacePath          := "/home/djm/SFML"
ProjectPath            := "/home/djm/SFML/RealGui2.0"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=DJM
Date                   :=14/07/17
CodeLitePath           :="/home/djm/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="RealGui.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch)C:/Users/DJM/Documents/SFML-2.4.1/include $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-system $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-graphics" "sfml-system" "sfml-window" "sfml-graphics" "sfml-window" "sfml-system" 
LibPath                := $(LibraryPathSwitch)C:/Users/DJM/Documents/SFML-2.4.1/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/RealGui.cpp$(ObjectSuffix) $(IntermediateDirectory)/board.cpp$(ObjectSuffix) $(IntermediateDirectory)/BUTTON.cpp$(ObjectSuffix) $(IntermediateDirectory)/LAYER.cpp$(ObjectSuffix) $(IntermediateDirectory)/TEXTING.cpp$(ObjectSuffix) $(IntermediateDirectory)/MOUSE.cpp$(ObjectSuffix) $(IntermediateDirectory)/IMAGE.cpp$(ObjectSuffix) $(IntermediateDirectory)/SCROLLBAR.cpp$(ObjectSuffix) $(IntermediateDirectory)/BUTTONHANDLE.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/INPUT.cpp$(ObjectSuffix) $(IntermediateDirectory)/KEYBOARD.cpp$(ObjectSuffix) $(IntermediateDirectory)/BUTTONRECEIVER.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/RealGui.cpp$(ObjectSuffix): RealGui.cpp $(IntermediateDirectory)/RealGui.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/RealGui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RealGui.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RealGui.cpp$(DependSuffix): RealGui.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RealGui.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RealGui.cpp$(DependSuffix) -MM "RealGui.cpp"

$(IntermediateDirectory)/RealGui.cpp$(PreprocessSuffix): RealGui.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RealGui.cpp$(PreprocessSuffix) "RealGui.cpp"

$(IntermediateDirectory)/board.cpp$(ObjectSuffix): board.cpp $(IntermediateDirectory)/board.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/board.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/board.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/board.cpp$(DependSuffix): board.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/board.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/board.cpp$(DependSuffix) -MM "board.cpp"

$(IntermediateDirectory)/board.cpp$(PreprocessSuffix): board.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/board.cpp$(PreprocessSuffix) "board.cpp"

$(IntermediateDirectory)/BUTTON.cpp$(ObjectSuffix): BUTTON.cpp $(IntermediateDirectory)/BUTTON.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/BUTTON.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BUTTON.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BUTTON.cpp$(DependSuffix): BUTTON.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BUTTON.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BUTTON.cpp$(DependSuffix) -MM "BUTTON.cpp"

$(IntermediateDirectory)/BUTTON.cpp$(PreprocessSuffix): BUTTON.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BUTTON.cpp$(PreprocessSuffix) "BUTTON.cpp"

$(IntermediateDirectory)/LAYER.cpp$(ObjectSuffix): LAYER.cpp $(IntermediateDirectory)/LAYER.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/LAYER.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LAYER.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LAYER.cpp$(DependSuffix): LAYER.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LAYER.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LAYER.cpp$(DependSuffix) -MM "LAYER.cpp"

$(IntermediateDirectory)/LAYER.cpp$(PreprocessSuffix): LAYER.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LAYER.cpp$(PreprocessSuffix) "LAYER.cpp"

$(IntermediateDirectory)/TEXTING.cpp$(ObjectSuffix): TEXTING.cpp $(IntermediateDirectory)/TEXTING.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/TEXTING.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TEXTING.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TEXTING.cpp$(DependSuffix): TEXTING.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TEXTING.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TEXTING.cpp$(DependSuffix) -MM "TEXTING.cpp"

$(IntermediateDirectory)/TEXTING.cpp$(PreprocessSuffix): TEXTING.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TEXTING.cpp$(PreprocessSuffix) "TEXTING.cpp"

$(IntermediateDirectory)/MOUSE.cpp$(ObjectSuffix): MOUSE.cpp $(IntermediateDirectory)/MOUSE.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/MOUSE.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MOUSE.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MOUSE.cpp$(DependSuffix): MOUSE.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MOUSE.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MOUSE.cpp$(DependSuffix) -MM "MOUSE.cpp"

$(IntermediateDirectory)/MOUSE.cpp$(PreprocessSuffix): MOUSE.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MOUSE.cpp$(PreprocessSuffix) "MOUSE.cpp"

$(IntermediateDirectory)/IMAGE.cpp$(ObjectSuffix): IMAGE.cpp $(IntermediateDirectory)/IMAGE.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/IMAGE.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IMAGE.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IMAGE.cpp$(DependSuffix): IMAGE.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IMAGE.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IMAGE.cpp$(DependSuffix) -MM "IMAGE.cpp"

$(IntermediateDirectory)/IMAGE.cpp$(PreprocessSuffix): IMAGE.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IMAGE.cpp$(PreprocessSuffix) "IMAGE.cpp"

$(IntermediateDirectory)/SCROLLBAR.cpp$(ObjectSuffix): SCROLLBAR.cpp $(IntermediateDirectory)/SCROLLBAR.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/SCROLLBAR.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SCROLLBAR.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SCROLLBAR.cpp$(DependSuffix): SCROLLBAR.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SCROLLBAR.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SCROLLBAR.cpp$(DependSuffix) -MM "SCROLLBAR.cpp"

$(IntermediateDirectory)/SCROLLBAR.cpp$(PreprocessSuffix): SCROLLBAR.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SCROLLBAR.cpp$(PreprocessSuffix) "SCROLLBAR.cpp"

$(IntermediateDirectory)/BUTTONHANDLE.cpp$(ObjectSuffix): BUTTONHANDLE.cpp $(IntermediateDirectory)/BUTTONHANDLE.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/BUTTONHANDLE.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BUTTONHANDLE.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BUTTONHANDLE.cpp$(DependSuffix): BUTTONHANDLE.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BUTTONHANDLE.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BUTTONHANDLE.cpp$(DependSuffix) -MM "BUTTONHANDLE.cpp"

$(IntermediateDirectory)/BUTTONHANDLE.cpp$(PreprocessSuffix): BUTTONHANDLE.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BUTTONHANDLE.cpp$(PreprocessSuffix) "BUTTONHANDLE.cpp"

$(IntermediateDirectory)/INPUT.cpp$(ObjectSuffix): INPUT.cpp $(IntermediateDirectory)/INPUT.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/INPUT.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/INPUT.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/INPUT.cpp$(DependSuffix): INPUT.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/INPUT.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/INPUT.cpp$(DependSuffix) -MM "INPUT.cpp"

$(IntermediateDirectory)/INPUT.cpp$(PreprocessSuffix): INPUT.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/INPUT.cpp$(PreprocessSuffix) "INPUT.cpp"

$(IntermediateDirectory)/KEYBOARD.cpp$(ObjectSuffix): KEYBOARD.cpp $(IntermediateDirectory)/KEYBOARD.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/KEYBOARD.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/KEYBOARD.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/KEYBOARD.cpp$(DependSuffix): KEYBOARD.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/KEYBOARD.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/KEYBOARD.cpp$(DependSuffix) -MM "KEYBOARD.cpp"

$(IntermediateDirectory)/KEYBOARD.cpp$(PreprocessSuffix): KEYBOARD.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/KEYBOARD.cpp$(PreprocessSuffix) "KEYBOARD.cpp"

$(IntermediateDirectory)/BUTTONRECEIVER.cpp$(ObjectSuffix): BUTTONRECEIVER.cpp $(IntermediateDirectory)/BUTTONRECEIVER.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/djm/SFML/RealGui2.0/BUTTONRECEIVER.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BUTTONRECEIVER.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BUTTONRECEIVER.cpp$(DependSuffix): BUTTONRECEIVER.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BUTTONRECEIVER.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BUTTONRECEIVER.cpp$(DependSuffix) -MM "BUTTONRECEIVER.cpp"

$(IntermediateDirectory)/BUTTONRECEIVER.cpp$(PreprocessSuffix): BUTTONRECEIVER.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BUTTONRECEIVER.cpp$(PreprocessSuffix) "BUTTONRECEIVER.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


