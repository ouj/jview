mkdir obj
mkdir obj/cblocks
cd obj/cblocks
cmake -Wdev -G "CodeBlocks - Unix Makefiles" ../..
gnome-open *.cbp >/dev/null 2>/dev/null &
cd ../..
