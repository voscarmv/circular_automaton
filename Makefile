# circular_automaton, Copyright 2013 Vicente Oscar Mier Vela <vomv1988@gmail.com>
# This file is part of circular_automaton.

# circular_automaton is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# circular_automaton is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with circular_automaton. If not, see <http:#www.gnu.org/licenses/>.

LIBNAME = cellauto

all: circle

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
