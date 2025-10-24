# Script para compilar y ejecutar tests de libft en Windows

Write-Host "===========================================
" -ForegroundColor Cyan
Write-Host "  COMPILANDO Y EJECUTANDO TESTS LIBFT" -ForegroundColor Cyan
Write-Host "===========================================" -ForegroundColor Cyan
Write-Host ""

# Verificar si existe WSL
$wslExists = Get-Command wsl -ErrorAction SilentlyContinue

if ($wslExists) {
    Write-Host "✓ WSL detectado, usando gcc de Linux..." -ForegroundColor Green
    Write-Host ""
    
    # Obtener la ruta de WSL
    $wslPath = wsl pwd
    
    # Compilar con gcc en WSL
    wsl gcc -Wall -Wextra -Werror -g ft_isalpha.c ft_isdigitit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c test_libft.c -o test_libft
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✓ Compilación exitosa!" -ForegroundColor Green
        Write-Host ""
        
        # Ejecutar los tests
        wsl ./test_libft
        
        Write-Host ""
        Write-Host "===========================================" -ForegroundColor Cyan
        Write-Host "  Tests completados" -ForegroundColor Cyan
        Write-Host "===========================================" -ForegroundColor Cyan
    } else {
        Write-Host "✗ Error en la compilación" -ForegroundColor Red
        exit 1
    }
} else {
    Write-Host "✗ No se encontró WSL ni compilador de C" -ForegroundColor Red
    Write-Host ""
    Write-Host "Opciones:" -ForegroundColor Yellow
    Write-Host "1. Instalar WSL: wsl --install" -ForegroundColor White
    Write-Host "2. Instalar MinGW y agregar gcc al PATH" -ForegroundColor White
    Write-Host "3. Usar un entorno Linux (VM, WSL, etc.)" -ForegroundColor White
    exit 1
}
