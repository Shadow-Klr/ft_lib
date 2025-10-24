/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: testing <testing@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:11:00 by testing           #+#    #+#             */
/*   Updated: 2025/10/24 08:11:00 by testing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifdef __APPLE__
    #include <bsd/string.h>
#endif

/* Implementaciones de referencia para Windows */
#if defined(_WIN32) || defined(_WIN64)
size_t strlcpy(char *dst, const char *src, size_t size)
{
    size_t src_len = strlen(src);
    if (size > 0) {
        size_t copy_len = (src_len >= size) ? size - 1 : src_len;
        memcpy(dst, src, copy_len);
        dst[copy_len] = '\0';
    }
    return src_len;
}

size_t strlcat(char *dst, const char *src, size_t size)
{
    size_t dst_len = strlen(dst);
    size_t src_len = strlen(src);
    
    if (dst_len >= size)
        return size + src_len;
    
    size_t copy_len = size - dst_len - 1;
    if (src_len < copy_len)
        copy_len = src_len;
    
    memcpy(dst + dst_len, src, copy_len);
    dst[dst_len + copy_len] = '\0';
    
    return dst_len + src_len;
}
#endif

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define RESET "\033[0m"

int g_test_count = 0;
int g_test_passed = 0;
int g_test_failed = 0;

void print_test_header(const char *function_name)
{
    printf("\n%s========================================%s\n", BLUE, RESET);
    printf("%s  Testeando: %s%s\n", BLUE, function_name, RESET);
    printf("%s========================================%s\n", BLUE, RESET);
}

void print_result(const char *test_name, int passed, int expected, int got)
{
    g_test_count++;
    if (passed)
    {
        g_test_passed++;
        printf("%s[OK]%s %s\n", GREEN, RESET, test_name);
    }
    else
    {
        g_test_failed++;
        printf("%s[FAIL]%s %s - Esperado: %d, Obtenido: %d\n", 
               RED, RESET, test_name, expected, got);
    }
}

void print_result_str(const char *test_name, int passed, const char *expected, const char *got)
{
    g_test_count++;
    if (passed)
    {
        g_test_passed++;
        printf("%s[OK]%s %s\n", GREEN, RESET, test_name);
    }
    else
    {
        g_test_failed++;
        printf("%s[FAIL]%s %s - Esperado: \"%s\", Obtenido: \"%s\"\n", 
               RED, RESET, test_name, expected, got);
    }
}

void print_result_size(const char *test_name, int passed, size_t expected, size_t got)
{
    g_test_count++;
    if (passed)
    {
        g_test_passed++;
        printf("%s[OK]%s %s\n", GREEN, RESET, test_name);
    }
    else
    {
        g_test_failed++;
        printf("%s[FAIL]%s %s - Esperado: %zu, Obtenido: %zu\n", 
               RED, RESET, test_name, expected, got);
    }
}

/* ========== TESTS DE ft_isalpha ========== */
void test_ft_isalpha(void)
{
    print_test_header("ft_isalpha");
    
    printf("\n  [Letras minúsculas]\n");
    char lowercase[] = {'a', 'b', 'm', 'x', 'y', 'z'};
    for (int i = 0; i < 6; i++) {
        int c = lowercase[i];
        int expected = isalpha(c);
        int got = ft_isalpha(c);
        char test_name[100];
        sprintf(test_name, "  isalpha('%c' = %d)", c, c);
        print_result(test_name, (!!expected == !!got), !!expected, !!got);
    }
    
    printf("\n  [Letras mayúsculas]\n");
    char uppercase[] = {'A', 'B', 'M', 'X', 'Y', 'Z'};
    for (int i = 0; i < 6; i++) {
        int c = uppercase[i];
        int expected = isalpha(c);
        int got = ft_isalpha(c);
        char test_name[100];
        sprintf(test_name, "  isalpha('%c' = %d)", c, c);
        print_result(test_name, (!!expected == !!got), !!expected, !!got);
    }
    
    printf("\n  [Dígitos (deberían fallar)]\n");
    char digits[] = {'0', '1', '5', '9'};
    for (int i = 0; i < 4; i++) {
        int c = digits[i];
        int expected = isalpha(c);
        int got = ft_isalpha(c);
        char test_name[100];
        sprintf(test_name, "  isalpha('%c' = %d)", c, c);
        print_result(test_name, (!!expected == !!got), !!expected, !!got);
    }
    
    printf("\n  [Símbolos y espacios (deberían fallar)]\n");
    int symbols[] = {' ', '!', '@', '[', '`', '{', '~'};
    for (int i = 0; i < 7; i++) {
        int c = symbols[i];
        int expected = isalpha(c);
        int got = ft_isalpha(c);
        char test_name[100];
        sprintf(test_name, "  isalpha('%c' = %d)", (c >= 32 && c <= 126) ? c : '?', c);
        print_result(test_name, (!!expected == !!got), !!expected, !!got);
    }
    
    printf("\n  [Valores límite]\n");
    int limits[] = {-1, 0, 64, 65, 90, 91, 96, 97, 122, 123, 127, 255};
    for (int i = 0; i < 12; i++) {
        int c = limits[i];
        int expected = isalpha(c);
        int got = ft_isalpha(c);
        char test_name[100];
        sprintf(test_name, "  isalpha(%d)", c);
        print_result(test_name, (!!expected == !!got), !!expected, !!got);
    }
}

/* ========== TESTS DE ft_isdigit ========== */
void test_ft_isdigit(void)
{
    print_test_header("ft_isdigit");
    
    printf("\n  [Todos los dígitos 0-9]\n");
    for (int i = '0'; i <= '9'; i++) {
        int expected = isdigit(i);
        int got = ft_isdigit(i);
        char test_name[100];
        sprintf(test_name, "  isdigit('%c' = %d)", i, i);
        print_result(test_name, (!!expected == !!got), !!expected, !!got);
    }
    
    printf("\n  [Letras (deberían fallar)]\n");
    char letters[] = {'a', 'A', 'z', 'Z', 'm', 'M'};
    for (int i = 0; i < 6; i++) {
        int c = letters[i];
        int expected = isdigit(c);
        int got = ft_isdigit(c);
        char test_name[100];
        sprintf(test_name, "  isdigit('%c' = %d)", c, c);
        print_result(test_name, (!!expected == !!got), !!expected, !!got);
    }
    
    printf("\n  [Valores límite y adyacentes]\n");
    int limits[] = {47, 48, 57, 58, -1, 0, 127, 255};
    for (int i = 0; i < 8; i++) {
        int c = limits[i];
        int expected = isdigit(c);
        int got = ft_isdigit(c);
        char test_name[100];
        sprintf(test_name, "  isdigit(%d = '%c')", c, (c >= 32 && c <= 126) ? c : '?');
        print_result(test_name, (!!expected == !!got), !!expected, !!got);
    }
}

/* ========== TESTS DE ft_isalnum ========== */
void test_ft_isalnum(void)
{
    print_test_header("ft_isalnum");
    
    int test_values[] = {'a', 'Z', '0', '9', ' ', '@', '[', '/', ':', 127, -1, 0};
    int i = 0;
    
    while (i < 12)
    {
        int c = test_values[i];
        int expected = isalnum(c);
        int got = ft_isalnum(c);
        char test_name[100];
        sprintf(test_name, "isalnum(%d/'%c')", c, (c >= 32 && c <= 126) ? c : '?');
        print_result(test_name, (!!expected == !!got), !!expected, !!got);
        i++;
    }
}

/* ========== TESTS DE ft_isascii ========== */
void test_ft_isascii(void)
{
    print_test_header("ft_isascii");
    
    int test_values[] = {0, 1, 32, 65, 90, 97, 122, 126, 127, 128, 255, -1, -128};
    int i = 0;
    
    while (i < 13)
    {
        int c = test_values[i];
        int expected = isascii(c);
        int got = ft_isascii(c);
        char test_name[100];
        sprintf(test_name, "isascii(%d)", c);
        print_result(test_name, (!!expected == !!got), !!expected, !!got);
        i++;
    }
}

/* ========== TESTS DE ft_isprint ========== */
void test_ft_isprint(void)
{
    print_test_header("ft_isprint");
    
    int test_values[] = {31, 32, 65, 90, 97, 122, 126, 127, 0, 10, 13, -1};
    int i = 0;
    
    while (i < 12)
    {
        int c = test_values[i];
        int expected = isprint(c);
        int got = ft_isprint(c);
        char test_name[100];
        sprintf(test_name, "isprint(%d/'%c')", c, (c >= 32 && c <= 126) ? c : '?');
        print_result(test_name, (!!expected == !!got), !!expected, !!got);
        i++;
    }
}

/* ========== TESTS DE ft_toupper ========== */
void test_ft_toupper(void)
{
    print_test_header("ft_toupper");
    
    int test_values[] = {'a', 'z', 'm', 'A', 'Z', 'M', '0', '9', ' ', '@', 127, -1};
    int i = 0;
    
    while (i < 12)
    {
        int c = test_values[i];
        int expected = toupper(c);
        int got = ft_toupper(c);
        char test_name[100];
        sprintf(test_name, "toupper(%d/'%c')", c, (c >= 32 && c <= 126) ? c : '?');
        print_result(test_name, (expected == got), expected, got);
        i++;
    }
}

/* ========== TESTS DE ft_tolower ========== */
void test_ft_tolower(void)
{
    print_test_header("ft_tolower");
    
    int test_values[] = {'A', 'Z', 'M', 'a', 'z', 'm', '0', '9', ' ', '@', 127, -1};
    int i = 0;
    
    while (i < 12)
    {
        int c = test_values[i];
        int expected = tolower(c);
        int got = ft_tolower(c);
        char test_name[100];
        sprintf(test_name, "tolower(%d/'%c')", c, (c >= 32 && c <= 126) ? c : '?');
        print_result(test_name, (expected == got), expected, got);
        i++;
    }
}

/* ========== TESTS DE ft_strlcpy ========== */
void test_ft_strlcpy(void)
{
    print_test_header("ft_strlcpy");
    
    printf("\n  [Copia básica con buffer suficiente]\n");
    char dst1[50];
    char dst2[50];
    
    strcpy(dst1, "XXXXXXXXXXXXX");
    strcpy(dst2, "XXXXXXXXXXXXX");
    size_t r1 = strlcpy(dst1, "Hello", 50);
    size_t r2 = ft_strlcpy(dst2, "Hello", 50);
    print_result_size("  strlcpy(dst, \"Hello\", 50) - retorno", (r1 == r2), r1, r2);
    print_result_str("  strlcpy(dst, \"Hello\", 50) - contenido", (strcmp(dst1, dst2) == 0), dst1, dst2);
    
    printf("\n  [Copia con buffer limitado]\n");
    strcpy(dst1, "XXXXXXXXXXXXX");
    strcpy(dst2, "XXXXXXXXXXXXX");
    r1 = strlcpy(dst1, "Hello World", 6);
    r2 = ft_strlcpy(dst2, "Hello World", 6);
    print_result_size("  strlcpy(dst, \"Hello World\", 6) - retorno", (r1 == r2), r1, r2);
    print_result_str("  strlcpy(dst, \"Hello World\", 6) - contenido", (strcmp(dst1, dst2) == 0), dst1, dst2);
    
    printf("\n  [Copia de cadena vacía]\n");
    strcpy(dst1, "XXXXXXXXXXXXX");
    strcpy(dst2, "XXXXXXXXXXXXX");
    r1 = strlcpy(dst1, "", 50);
    r2 = ft_strlcpy(dst2, "", 50);
    print_result_size("  strlcpy(dst, \"\", 50) - retorno", (r1 == r2), r1, r2);
    print_result_str("  strlcpy(dst, \"\", 50) - contenido", (strcmp(dst1, dst2) == 0), dst1, dst2);
    
    printf("\n  [Buffer de tamaño 1]\n");
    strcpy(dst1, "XXXXXXXXXXXXX");
    strcpy(dst2, "XXXXXXXXXXXXX");
    r1 = strlcpy(dst1, "Test", 1);
    r2 = ft_strlcpy(dst2, "Test", 1);
    print_result_size("  strlcpy(dst, \"Test\", 1) - retorno", (r1 == r2), r1, r2);
    print_result_str("  strlcpy(dst, \"Test\", 1) - contenido", (strcmp(dst1, dst2) == 0), dst1, dst2);
    
    printf("\n  [Buffer de tamaño 0]\n");
    strcpy(dst1, "XXXXXXXXXXXXX");
    strcpy(dst2, "XXXXXXXXXXXXX");
    r1 = strlcpy(dst1, "Test", 0);
    r2 = ft_strlcpy(dst2, "Test", 0);
    print_result_size("  strlcpy(dst, \"Test\", 0) - retorno", (r1 == r2), r1, r2);
    print_result_str("  strlcpy(dst, \"Test\", 0) - contenido", (strcmp(dst1, dst2) == 0), dst1, dst2);
}

/* ========== TESTS DE ft_strlcat ========== */
void test_ft_strlcat(void)
{
    print_test_header("ft_strlcat");
    
    printf("\n  [Concatenación básica]\n");
    char dst1[50];
    char dst2[50];
    
    strcpy(dst1, "Hello");
    strcpy(dst2, "Hello");
    size_t r1 = strlcat(dst1, " World", 50);
    size_t r2 = ft_strlcat(dst2, " World", 50);
    print_result_size("  strlcat(\"Hello\", \" World\", 50) - retorno", (r1 == r2), r1, r2);
    print_result_str("  strlcat(\"Hello\", \" World\", 50) - contenido", (strcmp(dst1, dst2) == 0), dst1, dst2);
    
    printf("\n  [Concatenación con buffer limitado]\n");
    strcpy(dst1, "Hello");
    strcpy(dst2, "Hello");
    r1 = strlcat(dst1, " World", 10);
    r2 = ft_strlcat(dst2, " World", 10);
    print_result_size("  strlcat(\"Hello\", \" World\", 10) - retorno", (r1 == r2), r1, r2);
    print_result_str("  strlcat(\"Hello\", \" World\", 10) - contenido", (strcmp(dst1, dst2) == 0), dst1, dst2);
    
    printf("\n  [Concatenar a cadena vacía]\n");
    strcpy(dst1, "");
    strcpy(dst2, "");
    r1 = strlcat(dst1, "Test", 50);
    r2 = ft_strlcat(dst2, "Test", 50);
    print_result_size("  strlcat(\"\", \"Test\", 50) - retorno", (r1 == r2), r1, r2);
    print_result_str("  strlcat(\"\", \"Test\", 50) - contenido", (strcmp(dst1, dst2) == 0), dst1, dst2);
    
    printf("\n  [Concatenar cadena vacía]\n");
    strcpy(dst1, "Hello");
    strcpy(dst2, "Hello");
    r1 = strlcat(dst1, "", 50);
    r2 = ft_strlcat(dst2, "", 50);
    print_result_size("  strlcat(\"Hello\", \"\", 50) - retorno", (r1 == r2), r1, r2);
    print_result_str("  strlcat(\"Hello\", \"\", 50) - contenido", (strcmp(dst1, dst2) == 0), dst1, dst2);
    
    printf("\n  [Buffer exacto]\n");
    strcpy(dst1, "Hi");
    strcpy(dst2, "Hi");
    r1 = strlcat(dst1, "!", 4);
    r2 = ft_strlcat(dst2, "!", 4);
    print_result_size("  strlcat(\"Hi\", \"!\", 4) - retorno", (r1 == r2), r1, r2);
    print_result_str("  strlcat(\"Hi\", \"!\", 4) - contenido", (strcmp(dst1, dst2) == 0), dst1, dst2);
}

/* ========== TESTS DE ft_strlen ========== */
void test_ft_strlen(void)
{
    print_test_header("ft_strlen");
    
    printf("\n  [Cadenas vacías y cortas]\n");
    char *short_strings[] = {"", "a", "ab", "abc", NULL};
    for (int i = 0; short_strings[i] != NULL; i++) {
        size_t expected = strlen(short_strings[i]);
        size_t got = ft_strlen(short_strings[i]);
        char test_name[100];
        sprintf(test_name, "  strlen(\"%s\")", short_strings[i]);
        print_result_size(test_name, (expected == got), expected, got);
    }
    
    printf("\n  [Cadenas con palabras]\n");
    char *word_strings[] = {"Hello", "World", "Test", "Programming", NULL};
    for (int i = 0; word_strings[i] != NULL; i++) {
        size_t expected = strlen(word_strings[i]);
        size_t got = ft_strlen(word_strings[i]);
        char test_name[100];
        sprintf(test_name, "  strlen(\"%s\")", word_strings[i]);
        print_result_size(test_name, (expected == got), expected, got);
    }
    
    printf("\n  [Cadenas con espacios y símbolos]\n");
    char *special_strings[] = {
        "Hello World!",
        "Test 123",
        "@#$%^&*()",
        "Spaces   multiple",
        NULL
    };
    for (int i = 0; special_strings[i] != NULL; i++) {
        size_t expected = strlen(special_strings[i]);
        size_t got = ft_strlen(special_strings[i]);
        char test_name[100];
        sprintf(test_name, "  strlen(\"%s\")", special_strings[i]);
        print_result_size(test_name, (expected == got), expected, got);
    }
    
    printf("\n  [Cadenas largas]\n");
    char *long_strings[] = {
        "12345678901234567890",
        "This is a longer string to test the function",
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
        NULL
    };
    for (int i = 0; long_strings[i] != NULL; i++) {
        size_t expected = strlen(long_strings[i]);
        size_t got = ft_strlen(long_strings[i]);
        char test_name[150];
        if (strlen(long_strings[i]) > 30)
            sprintf(test_name, "  strlen(\"%.30s...\")", long_strings[i]);
        else
            sprintf(test_name, "  strlen(\"%s\")", long_strings[i]);
        print_result_size(test_name, (expected == got), expected, got);
    }
}

/* ========== MAIN ========== */
int main(void)
{
    printf("\n%s╔════════════════════════════════════════════╗%s\n", YELLOW, RESET);
    printf("%s║   SISTEMA DE TESTING AUTOMATICO - LIBFT   ║%s\n", YELLOW, RESET);
    printf("%s╚════════════════════════════════════════════╝%s\n", YELLOW, RESET);
    
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    test_ft_isascii();
    test_ft_isprint();
    test_ft_toupper();
    test_ft_tolower();
    test_ft_strlen();
    test_ft_strlcpy();
    test_ft_strlcat();
    
    printf("\n%s========================================%s\n", YELLOW, RESET);
    printf("%s         RESUMEN DE RESULTADOS         %s\n", YELLOW, RESET);
    printf("%s========================================%s\n", YELLOW, RESET);
    printf("Total de tests: %d\n", g_test_count);
    printf("%s✓ Tests pasados: %d%s\n", GREEN, g_test_passed, RESET);
    printf("%s✗ Tests fallados: %d%s\n", RED, g_test_failed, RESET);
    
    if (g_test_failed == 0)
        printf("\n%s¡TODOS LOS TESTS PASARON EXITOSAMENTE!%s\n\n", GREEN, RESET);
    else
        printf("\n%sHay %d tests que necesitan corrección.%s\n\n", RED, g_test_failed, RESET);
    
    return (g_test_failed > 0 ? 1 : 0);
}
