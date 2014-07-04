echo Search: $1
find linux/ -regex ".*\.c*[chx]" | xargs grep -n -e $1
