#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "../libft.h"
}

TEST(TestFtStrrchr, CharInStr) {
    char    s1[50] = {'0'};
    char    *p1, *p2;
    
    memcpy(s1, "This is Some\ntext.\0    ", 19);
    p1 = strrchr(s1, 'o');
    p2 = ft_strrchr(s1, 'o');
    EXPECT_EQ(p1, p2);
    p1 = strrchr(s1, 'x');
    p2 = ft_strrchr(s1, 'x');
    EXPECT_EQ(p1, p2);
    p1 = strrchr(s1, '\n');
    p2 = ft_strrchr(s1, '\n');
    EXPECT_EQ(p1, p2);
    p1 = strrchr(s1, 'S');
    p2 = ft_strrchr(s1, 'S');
    EXPECT_EQ(p1, p2);
}

TEST(TestFtStrrchr, FindTerminatoChar) {
    char    s1[50] = {'0'};
    char    *p1, *p2;
    
    memcpy(s1, "This is Some\ntext.\0    ", 19);
    p1 = strrchr(s1,  0);
    p2 = ft_strrchr(s1, 0);
    EXPECT_EQ(p1, p2);
}

TEST(TestFtStrrchr, CharAfterTerminator) {
    char    s1[50] = {'0'};
    char    *p1, *p2;
    
    memcpy(s1, "ghreuh gkF\tEs1e24j7 k9jF?U+h+5k\0rfwfeefkkkkk", 40);
    p1 = strrchr(s1, '0');
    p2 = ft_strrchr(s1, '0');
    EXPECT_EQ(p1, p2);
    p1 = strrchr(s1, 'f');
    p2 = ft_strrchr(s1, 'f');
    EXPECT_EQ(p1, p2);
}

TEST(TestFtStrrchr, CharNotInStr) {
    char    s1[50] = {'0'};
    char    *p1, *p2;
    
    s1[50] = 0;
    memcpy(s1, "no pqrs tuv wxyz aABC DEF", 20);
    p1 = strrchr(s1, ':');
    p2 = ft_strrchr(s1, ':');
    EXPECT_EQ(p1, p2);
    p1 = strrchr(s1, -49);
    p2 = ft_strrchr(s1, -49);
    EXPECT_EQ(p1, p2);
}