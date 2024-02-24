from PIL import Image, ImageFilter

#Abrir imagem
img1 = Image.open("carol.jpg")

#Criar kernel
kernel = ImageFilter.Kernel((3,3), (-1,-1,-1,-1,8,-1,-1,-1,-1), 1)

#Aplicar filtro na imagem
img2 = img1.filter(kernel)

#Salvar imagem
img2.save("carolborda.jpg")
