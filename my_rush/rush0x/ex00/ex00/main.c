/* ************************************************************************ */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerschl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:30:55 by jkerschl          #+#    #+#             */
/*   Updated: 2023/03/25 17:48:27 by jkerschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void compare_col_norm(int col1[4][6][4], int col2[4][6][4], int out_data[4][6][4]);
void get_possible_num(int arr[2],int out_arr[6][4]);
int *match_each_col_options(int col_options[6][4], int all_row_options[4][6][4], int col_pos, int row_pos, int row_arr,int out_arr[6][4]);

int main()
{	
	int first_col_options[6][4];
	int second_col_options[6][4];
	int third_col_options[6][4];
	int fourth_col_options[6][4];
	int first_row_options[6][4];
	int second_row_options[6][4];
	int third_row_options[6][4];
	int fourth_row_options[6][4];
	int all_row_options[4][6][4];
	int first_col[2] = {3,2};
	int second_col[2] = {1,4};
	int third_col[2] = {3,1};
	int fourth_col[2] = {3,2};
	int first_row[2] = {2,2};
	int second_row[2] = {3,1};
	int third_row[2] = {1,3};
	int fourth_row[2] = {2,2};
	int yyy;
	int yyyy;
	int i;
	int w;
	int zz;
	int z;

	int row_ct;
	int row_ct2;
	int *sw_out;
	int all_match;
	int out_arr[6][4];
	int out_arr_all[4][6][4];

	i = 0;
	w = 0;
	row_ct = 0;
	row_ct2 = 0;

	get_possible_num(first_col,first_col_options);
	get_possible_num(second_col,second_col_options);
	get_possible_num(third_col,third_col_options);
	get_possible_num(fourth_col,fourth_col_options);
	get_possible_num(first_row,first_row_options);
	get_possible_num(second_row,second_row_options);
	get_possible_num(third_row,third_row_options);
	get_possible_num(fourth_row,fourth_row_options);

	while(row_ct < 6)
	{
		while(row_ct2 < 4)
		{
			all_row_options[0][row_ct][row_ct2] = first_row_options[row_ct][row_ct2];
			row_ct2++;
		}
		row_ct2 = 0;
		row_ct++;
	}
	row_ct = 0;
	row_ct2 = 0;
	while(row_ct < 6)
	{
		while(row_ct2 < 4)
		{
			all_row_options[1][row_ct][row_ct2] = second_row_options[row_ct][row_ct2];
			row_ct2++;
		}
		row_ct2 = 0;
		row_ct++;
	}
	row_ct = 0;
	row_ct2 = 0;
	while(row_ct < 6)
	{
		while(row_ct2 < 4)
		{
			all_row_options[2][row_ct][row_ct2] = third_row_options[row_ct][row_ct2];
			row_ct2++;
		}
		row_ct2 = 0;
		row_ct++;
	}
	row_ct = 0;
	row_ct2 = 0;
	while(row_ct < 6)
	{
		while(row_ct2 < 4)
		{
			all_row_options[3][row_ct][row_ct2] = fourth_row_options[row_ct][row_ct2];
			row_ct2++;
		}
		row_ct2 = 0;
		row_ct++;
	}

	while(first_col_options[i][0]!=0 && i < 6)
	{
		all_match = 0;
		while(w<4)
		{

			yyy = 0;
			yyyy = 0;

			while (yyy < 6)
			{
				while (yyyy < 4)
				{
					out_arr[yyy][yyyy]=9;
					yyyy++;
				}
				yyy++;
				yyyy = 0;
			}

			sw_out = match_each_col_options(first_col_options,all_row_options,i,0,w,out_arr);
			if(*sw_out==0)
			{
				break;
			}
			else
			{
				zz = 0;
				z = 0;
				while(zz < 6)
				{
					while(z < 4)
					{
						out_arr_all[w][zz][z] = out_arr[zz][z];
						z++;
					}
					z = 0;
					zz++;
				}
			}
			w++;
			all_match = all_match + *sw_out;
		}
		w = 0;
		// if (all_match == 4)
		// {
		// 	printf("%s","======all_match\n");
		// 	for(int zzz = 0; zzz < 4; zzz++){
		// 		for(int zz = 0; zz < 6; zz++) {
		// 			for(int z = 0; z < 4; z++) {
		// 				printf("%d", out_arr_all[zzz][zz][z]);
		// 			}
		// 			printf("\n");
		// 		}
		// 		printf("*********\n");
		// 	}
		// }
		i++;
	}
}

