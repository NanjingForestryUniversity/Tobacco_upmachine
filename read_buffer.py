import numpy as np
import matplotlib.pyplot as plt

img_names = [f"mask_result{i}" for i in range(23, 40)]
mask_names = [f"padding_result{i}" for i in range(23, 40)]

for img_name, mask_name in zip(img_names,mask_names):
    with open(img_name, "rb") as f:
        data = f.read()
    with open(mask_name, "rb") as f:
        data_mask = f.read()
    img = np.frombuffer(data, dtype=np.uint8).reshape((1024, 256, -1))
    mask = np.frombuffer(data_mask, dtype=np.uint8).reshape((1024, 256, -1))
    fig, axs = plt.subplots(2, 1, constrained_layout=True)
    axs[0].imshow(img)
    #axs[0].set_title(f'mask_result{i}')
    axs[1].imshow(mask)
    #axs[1].set_title(f'padding_result{i}')
    plt.title(f"img : {img_name}")
    plt.show()
