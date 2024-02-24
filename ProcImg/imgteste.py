from tkinter import *
from PIL import Image, ImageDraw, ImageTk

# Função para mostrar a imagem no Tkinter
def mostrar_imagem():
    imagem.save("imgteste.png") #salva a imagem em um arquivo
    img = ImageTk.PhotoImage(Image.open("imgteste.png"))

    label_imagem = Label(janela, image=img)
    label_imagem.image = img

    label_imagem.pack()

janela = Tk()
janela.title("imagem")
janela.geometry("600x600")

branco = (255, 255, 255)
imagem = Image.new("RGB", (500,500), branco)

pixels = imagem.load()
largura, altura = imagem.size

for x in range(largura):
    for y in range(altura):
        if x < y or x > y+5 :
            pixels[x, y] = (0, 0, 0)
    
mostrar_imagem()
#desenho = ImageDraw.Draw(imagem)
#desenho.ellipse((100, 100, 200, 200), fill=(150, 100, 255))

botao_mostrar = Button(janela, text="Mostrar Imagem", command=mostrar_imagem)
botao_mostrar.pack()
janela.mainloop()
