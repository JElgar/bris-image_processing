default: first

image1: image1.cpp
	g++ image1.cpp -o first -Wl,-rpath,/usr/local/lib `pkg-config --cflags --libs opencv4`

first: first.cpp
	g++ first.cpp -o first -Wl,-rpath,/usr/local/lib `pkg-config --cflags --libs opencv4`
