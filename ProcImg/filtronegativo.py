from PIL import Image
"""
#Criar imagem
img = Image.new("RGB", (7,7))
pixel_data = img.load()  # create the pixel map

#Definir pixels da imagem   
for x in range(img.width):
    for y in range(img.height):
        if(x < y):
            pixel_data[x, y] = (255, 255, 255)  # set pixel color to white
#Salvar a imagem
img.save("negativo.png")   
#Mostrar a imagem
img.show()"""

#Abrir imagem
img = Image.open("gray_baloes2.jpg")

#Carregar a imagem para uma matriz
matriz = img.load()

#Definir largura e altura da imagem
largura = img.width
altura = img.height

#Definir pixels da imagem
for x in range(largura):
    for y in range(altura):
        r = 255 - matriz[x, y][0]
        g = 255 - matriz[x, y][1]
        b = 255 - matriz[x, y][2]
        matriz[x, y] = (r, g, b)

#Salvar a imagem
img.save("baloesNegativo.png")