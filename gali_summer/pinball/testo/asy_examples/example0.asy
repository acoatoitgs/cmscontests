import math;
size(100,0);

add(grid(10,10));

draw((1,1)--(1,5), orange+linewidth(1));
draw((1,5)--(5,5), orange+linewidth(1));
draw((5,5)--(5,1), orange+linewidth(1));
draw((5,1)--(1,1), orange+linewidth(1));
dot((1,1),blue);
dot((1,5),blue);
dot((2,3),blue);
dot((5,5),blue);
dot((5,1),blue);


for(int i = 2; i <= 4; ++i)
{
    for(int k = 2; k <= 4; ++k)
    {
        draw(circle((i,k), 0.3), red+linewidth(0.8));
    }
}

for (int i = 0; i <= 10; ++i) {
    label(scale(0.5)*string(i), (i, 0), S);
    label(scale(0.5)*string(i), (0, i), W);
}