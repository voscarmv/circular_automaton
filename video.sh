#!/bin/bash

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

while read FNAME CELLSAREA CIRCLEAREA CELLSTOCIRCLE HITS HITSTOCIRCLE; do
	echo File name $FNAME
	echo Cells $CELLSAREA
	echo Circle $CIRCLEAREA
	echo Cells to circle $CELLSTOCIRCLE%
	echo Hits $HITS
	echo Hits to circle $HITSTOCIRCLE%

	ITER=`echo $FNAME | sed 's/img\/cell//;s/.ppm//'`

	if test $CIRCLEAREA -ge $CELLSAREA ; then
		ANNOTATION="Iteracion: $ITER\nPixels del disco: $CIRCLEAREA\nPixels del cultivo: $CELLSAREA\nHay $HITS pixels del cultivo dentro del disco\nEl disco esta $HITSTOCIRCLE\% lleno\nEl area del cultivo es $CELLSTOCIRCLE\% el area del disco\n\n"
		FILL='#00ff00'
	else
		ANNOTATION="CULTIVO > DISCO\nIteracion: $ITER\nPixels del disco: $CIRCLEAREA\nPixels del cultivo: $CELLSAREA\nHay $HITS pixels del cultivo dentro del disco\nEl disco esta $HITSTOCIRCLE\% lleno\nEl area del cultivo es $CELLSTOCIRCLE\% el area del disco\n\n"
	fi

	FILE=`echo $FNAME | sed 's/.ppm//'`
	convert $FNAME -gravity southwest \
		-stroke none -fill $FILL -annotate 0 "$ANNOTATION" \
		$FILE.png

	echo Created $FILE.png
	echo
done
