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

// #include <stdio.h>

void get_possible_num(int arr[2],int out_arr[6][4])
{
	int s_all[9][7][4] = {
		{{1,2,0,0},{4,1,2,3},{4,2,1,3},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
		{{1,3,0,0},{4,2,3,1},{4,1,3,2},{4,3,1,2},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
		{{1,4,0,0},{4,3,2,1},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
		{{2,1,0,0},{3,1,2,4},{3,2,1,4},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
		{{2,2,0,0},{3,1,4,2},{3,2,4,1},{3,4,1,2},{2,4,1,3},{1,4,2,3},{2,1,4,3}},
		{{2,3,0,0},{3,4,2,1},{1,4,3,2},{2,4,3,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
		{{3,1,0,0},{1,3,2,4},{2,1,3,4},{2,3,1,4},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
		{{3,2,0,0},{1,2,4,3},{1,3,4,2},{2,3,4,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
		{{4,1,0,0},{1,2,3,4},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}};

	int i = 0;
	int j = 0;
	int k = 0;
	while(i<9)
	{
		if(arr[0]==s_all[i][0][0] && arr[1]==s_all[i][0][1])
		{
			while(j<7)
			{
				while(k<4)
				{
					out_arr[j][k] = s_all[i][j+1][k];
					k++;
					
				}
				k = 0;
				j++;
			}
		}
		i++;
		j = 0;
	}
}

// int main()
// {
// 	int first_col[2] = {1,4};
// 	int first_col_options[6][4] = {{9,9,9,9},{9,9,9,9},{9,9,9,9},{9,9,9,9},{9,9,9,9},{9,9,9,9}};
// 	get_possible_num(first_col,first_col_options);
// 	int yyy = 0;
// 	int yyyy = 0;

// 	while (yyy < 6)
// 	{
// 		while (yyyy < 4)
// 		{
// 			printf("%d",first_col_options[yyy][yyyy]);
// 			yyyy++;
// 		}
// 		printf("\n");
// 		yyy++;
// 		yyyy = 0;
// 	}
// }