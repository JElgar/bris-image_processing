default: hello-clean.cpp
	g++ hello-clean.cpp -Wl,-rpath,/usr/local/lib `pkg-config --cflags --libs opencv4` -o output
