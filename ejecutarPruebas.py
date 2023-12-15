import subprocess
import random

def generar_datos():
    pass

def generar_input(modo):
    programa_path = "./generateInput"
    
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
        print(resultado.stdout, end="")
    except subprocess.CalledProcessError as e:
        print(f"Error al ejecutar el programa: {e}")

if __name__ == "__main__":
    arboles = ['./AVL', './RedBlackTree', './SplayTree']
    modos = ['balanced', 'inserts', 'deletes', 'searches']

    for i in range(250):
        modo = modos[random.randint(0, len(modos)-1)]
        arbol = arboles[random.randint(0, len(arboles)-1)]
        # print(f"{i}: {modo} - {arbol}")
        generar_input(modo)
        ejecutar_programa(arbol);
        print(f" {modo}")
