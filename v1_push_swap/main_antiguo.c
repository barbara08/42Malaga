#include "push_swap.h"


//Para ejecutar (con wc -l saldrá la cantidad de movimientos)
// ./push_swap números | wc -l

/*  100 números aleatorios en menos de 700
operaciones

500 números aleatorios, no
deberás superar las 5500 operaciones
*/

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0); // No argumentos, no imprimir nada

	int *stack_a;
	int size_a = argc - 1;
	int *stack_b;
	int size_b = 0;
	int i;
	int error = 0;

	stack_a = (int *)malloc(sizeof(int) * size_a);
	if (!stack_a)
		return 1;
	stack_b = (int *)malloc(sizeof(int) * size_a);
	if (!stack_b)
	{
		free(stack_a);
		return (1);
	}

	// Convertir argv a int con validación
	i = 0;
	while (i < size_a)
	{
		stack_a[i] = ft_atoi_validate(argv[i + 1], &error);
		if (error)
		{
			//ft_putstr_fd("Error\n", 2);
			write(2, "Error\n", 6);
			free(stack_a);
			free(stack_b);
			return (1);
		}
		i++;
	}

	// Duplicados
	if (ft_number_duplicate(stack_a, size_a))
	{
		//ft_putstr_fd("Error\n", 2);
		write(2, "Error\n", 6);  //El 2 es para los errores
		free(stack_a);
		free(stack_b);
		return (1);
	}

	// Si ya está ordenado no hace nada
	if (ft_is_sorted(stack_a, size_a))
	{
		free(stack_a);
		free(stack_b);
		return (0);
	}

	// Ordenación de: 
	//hasta 3 elementos, hasta 5 elementos y a partir del 6º elemento
	if (size_a <= 3)
		ft_sort_three(stack_a, size_a);
	else if (size_a <= 5)
		ft_sort_five(stack_a, &size_a, stack_b, &size_b);
	else
	{
		ft_index_stack(stack_a, size_a);
		ft_sort_big(stack_a, &size_a, stack_b, &size_b);
	}

	free(stack_a);
	free(stack_b);
	return (0);
}

/*
write(0, "Error\n", 6); 
0 es stdin (entrada estándar)

write(1, "Error\n", 6); 
1 es stdout (salida estándar, la consola normal)

write(2, "Error\n", 6); 
2 es stderr (salida de errores)
*/


//100 numeros
//837 12 984 451 390 761 658 477 705 232 83 901 673 39 118 206 569 60 810 158 297 906 385 245 970 688 544 510 241 775 691 344 866 933 681 119 200 399 436 148 646 976 927 741 294 813 156 519 449 878 295 142 273 243 259 459 889 370 214 474 26 955 372 709 778 164 69 350 91 264 438 849 266 288 172 590 707 132 174 543 341 84 541 702 748 347 611 836 772 249 363 110 530 356 291 336 388 194

//500 numeros
//815 757 723 841 830 298 20 140 933 170 212 759 730 709 181 477 412 799 376 489 131 147 696 306 9 977 98 61 505 518 887 179 36 738 287 37 437 465 151 196 33 178 674 652 598 508 86 952 684 684 167 564 390 519 811 902 93 689 898 764 583 938 589 755 848 569 987 427 858 681 938 318 734 554 399 269 495 702 254 635 221 915 191 408 150 38 373 594 956 199 537 509 13 887 105 638 481 530 408 606 523 220 322 603 930 133 334 867 97 925 27 48 265 557 336 668 981 712 697 948 126 587 647 391 576 399 174 939 890 494 482 444 659 901 722 239 855 990 247 968 733 772 71 945 573 186 528 837 925 711 715 387 616 952 716 158 925 273 518 679 858 571 120 872 323 334 490 434 473 174 661 969 413 35 44 888 607 26 184 963 204 70 377 768 984 424 684 445 893 893 966 106 276 47 177 659 886 642 17 28 715 167 957 889 930 875 688 839 213 278 610 931 271 356 521 827 727 881 278 135 397 717 172 649 24 628 397 299 92 917 881 378 921 727 416 279 852 387 752 865 603 331 301 338 788 309 45 818 780 327 138 816 101 458 385 83 567 428 429 857 207 157 142 481 427 320 384 700 626 76 463 959 759 331 123 203 904 679 341 519 326 362 187 113 389 592 355 748 434 353 666 335 752 14 552 316 336 495 749 224 505 893 36
