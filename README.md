# stattop

Accepts a stream of integers, one per line, and calculates a running mean/standard deviation.

## Example Usage

```
for i in 0 1 2 3 4 5 6 7 8 9; do
  echo $i >> numbers.txt
done

cat numbers.txt | ./stattop
```

Output:
```
last=9 count=10 mean=4 std_dev=3
```

Also accepts a stream, here is an example of parsing times from a logfile tail:

```tail -f logfile | gawk 'match($0, /time=([0-9]+)ms/, m) {print m[1];system("")}' | ./stattop```

## Building

```./build.sh```

Which is really just:

```gcc -o stattop stattop.c -lm```

Should compile on any POSIX system.

## License

The MIT License (MIT)

Copyright © 2020 Kennon Ballou

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
