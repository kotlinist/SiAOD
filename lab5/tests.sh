cat lab5/6__1ncxc.txt | xargs -0 ./kmp -i SEI
cat lab5/6__1ncxc.txt | xargs -0 ./bm -i SEI
hyperfine --warmup 10 'cat lab5/6__1ncxc.txt | xargs -0 ./kmp -i SEI' 'cat lab5/6__1ncxc.txt | xargs -0 ./bm -i SEI'