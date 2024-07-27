import math;
size(100,0);

add(grid(10,10));

draw((1,3)--(6,1), orange+linewidth(1));
draw((6,1)--(8,2), orange+linewidth(1));
draw((8,2)--(9,5), orange+linewidth(1));
draw((9,5)--(1,4), orange+linewidth(1));
draw((1,4)--(1,3), orange+linewidth(1));

dot((8,2),blue);
dot((6,1),blue);
dot((1,4),blue);
dot((8,3),blue);
dot((9,5),blue);
dot((1,3),blue);
dot((8,3),blue);
dot((7,2),blue);

draw(circle((4,2), 0.2), red+linewidth(0.6));
draw(circle((5,2), 0.2), red+linewidth(0.6));
draw(circle((6,2), 0.2), red+linewidth(0.6));
draw(circle((7,2), 0.2), red+linewidth(0.6));

draw(circle((2,3), 0.2), red+linewidth(0.6));
draw(circle((3,3), 0.2), red+linewidth(0.6));
draw(circle((4,3), 0.2), red+linewidth(0.6));
draw(circle((5,3), 0.2), red+linewidth(0.6));
draw(circle((6,3), 0.2), red+linewidth(0.6));
draw(circle((7,3), 0.2), red+linewidth(0.6));
draw(circle((8,3), 0.2), red+linewidth(0.6));

draw(circle((2,4), 0.2), red+linewidth(0.6));
draw(circle((3,4), 0.2), red+linewidth(0.6));
draw(circle((4,4), 0.2), red+linewidth(0.6));
draw(circle((5,4), 0.2), red+linewidth(0.6));
draw(circle((6,4), 0.2), red+linewidth(0.6));
draw(circle((7,4), 0.2), red+linewidth(0.6));
draw(circle((8,4), 0.2), red+linewidth(0.6));


for (int i = 0; i <= 10; ++i) {
    label(scale(0.5)*string(i), (i, 0), S);
    label(scale(0.5)*string(i), (0, i), W);
}