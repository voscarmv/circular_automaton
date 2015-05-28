#!/bin/bash

while read FNAME CELLSAREA CIRCLEAREA CELLSTOCIRCLE HITS HITSTOCIRCLE; do
	echo File name $FNAME
	echo Cells $CELLSAREA
	echo Circle $CIRCLEAREA
	echo Cells to circle $CELLSTOCIRCLE%
	echo Hits $HITS
	echo Hits to circle $HITSTOCIRCLE%
	echo Done.

	ITER=`echo $FNAME | sed 's/cell//;s/.ppm//'`

	if test $CIRCLEAREA -ge $CELLSAREA ; then
		ANNOTATION="Iteration: $ITER\nPixels in circle: $CIRCLEAREA\nPixels in culture: $CELLSAREA\nCulture pixels inside circle: $HITS\nPercentage of circle filled: $HITSTOCIRCLE\%\nCulture area is $CELLSTOCIRCLE\% the area of the circle"
		FILL='#00ff00'
	else
		ANNOTATION="CULTURE AREA > CIRCLE AREA\nIteration: $ITER\nPixels in circle: $CIRCLEAREA\nPixels in culture: $CELLSAREA\nCulture pixels inside circle: $HITS\nPercentage of circle filled: $HITSTOCIRCLE\%\nCulture area is $CELLSTOCIRCLE\% the area of the circle"
	fi

  convert $FNAME -gravity southwest \
          -stroke none -fill $FILL -annotate 0 "$ANNOTATION" \
          $FNAME.png
done