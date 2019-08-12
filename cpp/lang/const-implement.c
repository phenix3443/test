TEST (BuildinTypeTest, ReferTest) {
    int x = 1;
    int y = 2;
    int &b = x;
    printf ("&x=%x,&y=%x,&b=%x,b=%x\n", &x, &y, &y - 1, *(&y - 1));
}
