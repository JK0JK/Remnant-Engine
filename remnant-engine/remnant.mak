#---------------------------------------------------------------------------------------------------------------------  
# Remnant Engine - automatically add engine directories to build  
#--------------------------------------------------------------------------------------------------------------------- 

SOURCES     	+=  $(shell find $(addsuffix /src,$(LIBREMNANT)) -type d 2>/dev/null)
INCLUDES    	+=  $(shell find $(addsuffix /include,$(LIBREMNANT)) -type d 2>/dev/null) 
GRAPHICS    	+=  $(shell find $(addsuffix /graphics,$(LIBREMNANT)) -type d 2>/dev/null)
AUDIO       	+=  $(shell find $(addsuffix /audio,$(LIBREMNANT)) -type d 2>/dev/null)
DMGAUDIO    	+=  $(shell find $(addsuffix /dmg_audio,$(LIBREMNANT)) -type d 2>/dev/null) 