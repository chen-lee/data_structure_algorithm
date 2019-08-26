CC:= g++
BUILD_DIR:=./build
OBJS_DIR:=$(BUILD_DIR)/objs

CFLAGS:=-std=c++14 -O2
INCLUDES:= -I.
LDFLAGS:=
ALL_SRC:=$(shell ls sort/*.cpp)
MS_SRC+=mergeSortMain.cpp $(ALL_SRC)
MS_OBJS:=$(foreach f, $(MS_SRC), $(addprefix $(OBJS_DIR)/$(dir $(f)), $(basename $(notdir $(f))).o))

$(OBJS_DIR)/%.o: %.cpp
	@if [ ! -d $(dir $@) ]; then echo dir $(dir $@) not exist, create it && mkdir -p $(dir $@); fi
	$(CC) -c $(CFLAGS) $(INCLUDES) -o $@ $<

MS_EXE=mergesort
$(MS_EXE): $(MS_OBJS)
	$(CC) $(MS_OBJS) -o $@ $(LDFLAGS)

clean:
	@echo "clean objects"
	rm -rf $(MS_OBJS) $(MS_EXE)