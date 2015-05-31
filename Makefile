# gcc -L. -I. -o b4 b4.c -lm -lcellauto

LIBNAME = cellauto

all: circle

# circle: circle.c lib${LIBNAME}.a lib${LIBNAME}.h
circle: circle.c lib${LIBNAME}.a
	gcc -L. -I. -o ${@} ${<} -lm -l${LIBNAME}

lib${LIBNAME}.o: lib${LIBNAME}.c
	gcc -c ${<} -lm

lib${LIBNAME}.a: lib${LIBNAME}.o
	ar rs ${@} ${<}

clean:
	rm -f *.a *.o img/*.ppm img/*.png *.mp4 *.log circle video

video: cell.mp4

cell.mp4: img/*.png
	avconv -framerate 5 -f image2 -i img/cell%04d.png -b 65536k cell.mp4

img/*.png: img/*.ppm
	cat culture.log | ./video.sh

img/*.ppm: circle
	./circle | tee culture.log

#video: circle
#	./circle | tee culture.log
#	cat culture.log | ./video.sh
#	avconv -framerate 5 -f image2 -i img/cell%04d.png -b 65536k cell.mp4
