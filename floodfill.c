typedef struct s_point {
    int x;
    int y;
} t_point;

void fill(int **tab, t_point size, t_point begin)
{
    if (begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y || tab[begin.y][begin.x] != 0)
        return;
    tab[begin.y][begin.x] = -1;
    fill(tab, size, (t_point){begin.x + 1, begin.y});
    fill(tab, size, (t_point){begin.x - 1, begin.y});
    fill(tab, size, (t_point){begin.x, begin.y + 1});
    fill(tab, size, (t_point){begin.x, begin.y - 1});
}

void  flood_fill(int **tab, t_point size, t_point begin)
{
    fill(tab, size, begin);
}
