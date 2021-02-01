# Maximum queens on the board

## Task

The task is to find the maximum number of queens on the chess board so there is no queens is attacked by any other queen.

The task must be done by a program on the C language.

## Preparing

One row (or column) can conain only one queen. So maximum queens count can not be greater than 8.

I can set the first queen onto the board, e. q. [a 1], then I can mark all attacked (threatened?) fields.

Then I can set the second queen to an unmarked (empty) position. Then I can mark all new attacked fields, and so on. If the result queen count is less than 8, I need go back to mark the last queen position as wrong and to find new empty position.

I can solve this task by recursive way.

I can use a memory buffer for at most 8 recursive step, so I can use a static variable due to avoid memory leaks errors and overhead on memory allocation/release.

## Result

Teoretical maximum queen count can be reached.

The program output shows at least 8 decisions. This decisions can be also mirrored and rotated.

```bash
 --- 
First queen at [a1]:
    a b c d e f g h
1 : Q x x x x x x x
2 : x x x x x x Q x
3 : x x x x Q x x x
4 : x x x x x x x Q
5 : x Q x x x x x x
6 : x x x Q x x x x
7 : x x x x x Q x x
8 : x x Q x x x x x
[a1] [b5] [c8] [d6] [e3] [f7] [g2] [h4] 
 --- 
First queen at [a2]:
    a b c d e f g h
1 : x x x x x Q x x
2 : Q x x x x x x x
3 : x x x x Q x x x
4 : x Q x x x x x x
5 : x x x x x x x Q
6 : x x Q x x x x x
7 : x x x x x x Q x
8 : x x x Q x x x x
[a2] [b4] [c6] [d8] [e3] [f1] [g7] [h5] 
 --- 
First queen at [a3]:
    a b c d e f g h
1 : x Q x x x x x x
2 : x x x x x Q x x
3 : Q x x x x x x x
4 : x x x x x x Q x
5 : x x x Q x x x x
6 : x x x x x x x Q
7 : x x Q x x x x x
8 : x x x x Q x x x
[a3] [b1] [c7] [d5] [e8] [f2] [g4] [h6] 
 --- 
First queen at [a4]:
    a b c d e f g h
1 : x Q x x x x x x
2 : x x x x Q x x x
3 : x x x x x x Q x
4 : Q x x x x x x x
5 : x x Q x x x x x
6 : x x x x x x x Q
7 : x x x x x Q x x
8 : x x x Q x x x x
[a4] [b1] [c5] [d8] [e2] [f7] [g3] [h6] 
 --- 
First queen at [a5]:
    a b c d e f g h
1 : x Q x x x x x x
2 : x x x x x Q x x
3 : x x x x x x x Q
4 : x x Q x x x x x
5 : Q x x x x x x x
6 : x x x Q x x x x
7 : x x x x x x Q x
8 : x x x x Q x x x
[a5] [b1] [c4] [d6] [e8] [f2] [g7] [h3] 
 --- 
First queen at [a6]:
    a b c d e f g h
1 : x Q x x x x x x
2 : x x x Q x x x x
3 : x x x x x Q x x
4 : x x x x x x x Q
5 : x x Q x x x x x
6 : Q x x x x x x x
7 : x x x x x x Q x
8 : x x x x Q x x x
[a6] [b1] [c5] [d2] [e8] [f3] [g7] [h4] 
 --- 
First queen at [a7]:
    a b c d e f g h
1 : x Q x x x x x x
2 : x x x x x x Q x
3 : x x Q x x x x x
4 : x x x x x Q x x
5 : x x x x x x x Q
6 : x x x x Q x x x
7 : Q x x x x x x x
8 : x x x Q x x x x
[a7] [b1] [c3] [d8] [e6] [f4] [g2] [h5] 
 --- 
First queen at [a8]:
    a b c d e f g h
1 : x x x Q x x x x
2 : x Q x x x x x x
3 : x x x x x x Q x
4 : x x Q x x x x x
5 : x x x x x Q x x
6 : x x x x x x x Q
7 : x x x x Q x x x
8 : Q x x x x x x x
[a8] [b2] [c4] [d1] [e7] [f5] [g3] [h6] 
```
