from PIL import Image, ImageFilter

# Carregar a imagem
img = Image.open('carolgray.jpg')

# Converter para escala de cinza
gray_img = img.convert('L')

# Aplicar filtro de mediana
#gray_img = gray_img.filter(ImageFilter.MedianFilter())

# Aplicar threshold usando a função point
threshold_value = 147
binary_img = gray_img.point(lambda x: 0 if x < threshold_value else 255, '1')

# Exibir as imagens original e binarizada
img.show(title='Imagem Original')
binary_img.show(title='Imagem Binarizada')

# Salvar a imagem binarizada
binary_img.save('carolthreshold.jpg')
