import subprocess
import random

def generar_datos():
    pass

def generar_input(modo):
    programa_path = "./generarInput"
    
    input_path = "input.txt"
    
    comando = [programa_path] + [f"400000 400000 {modo}",">", input_path]

    try:
        subprocess.run(" ".join(comando), shell=True, check=True, stdout=subprocess.PIPE, text=True)
    except subprocess.CalledProcessError as e:
        print(f"Error al ejecutar el programa: {e}")


def ejecutar_programa(arbol):
    input_path = "input.txt"
    
    comando = [arbol] + ["<", input_path]

    try:
        resultado = subprocess.run(" ".join(comando), shell=True, check=True, stdout=subprocess.PIPE, text=True)
        print(resultado.stdout)
    except subprocess.CalledProcessError as e:
        print(f"Error al ejecutar el programa: {e}")

if __name__ == "__main__":
    for i in range(5):
        ejecutar_programa();
