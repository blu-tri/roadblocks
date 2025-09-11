roadblocks: src/main.cpp
	clang++ src/main.cpp -o roadblocks -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
	
clean:
	rm -ivr roadblocks lib/*
