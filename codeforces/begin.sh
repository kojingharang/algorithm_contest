if [ "$1" = "" ]
then
	echo "$0 <problem number>"
	exit
fi

cp -n template.cpp $1a.cpp
cp -n template.cpp $1b.cpp
cp -n template.cpp $1c.cpp
cp -n template.cpp $1d.cpp
cp -n template.cpp $1e.cpp

