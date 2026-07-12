#---------------------------------------------------------------------------------------------------------------------  
# Remnant Engine - automatically add engine directories to build  
#---------------------------------------------------------------------------------------------------------------------  
  
# Add remnant-engine source directories to SOURCES  
SOURCES     	+=  $(shell find $(LIBREMNANT)/src -type d 2>/dev/null)
  
# Add remnant-engine include directories to INCLUDES    
INCLUDES    	+=  $(shell find $(LIBREMNANT)/include -type d 2>/dev/null) 

# Add remnant-engine graphics directories to GRAPHICS  
GRAPHICS    	+=  $(shell find $(LIBREMNANT)/graphics -type d 2>/dev/null) 
  
# Add remnant-engine audio directories to AUDIO  
AUDIO       	+=  $(shell find $(LIBREMNANT)/audio -type d 2>/dev/null) 
  
# Add remnant-engine dmg_audio directories to DMGAUDIO  
DMGAUDIO    	+=  $(shell find $(LIBREMNANT)/dmg_audio -type d 2>/dev/null) 