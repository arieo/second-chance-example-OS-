#include <iostream>
using namespace std;

struct frame
{
	bool reference_bit = false;
	int value = 0;
};
//if the frame existet then reference_bit = true
bool exist(frame frame[], int num_of_F, int page)
{
	for (size_t i = 0; i < num_of_F; i++)
	{
		if (frame[i].value == page)
		{
			frame[i].reference_bit = true;
			return true;
		}
	}
	return false;
}

int sum_of_PF(frame frames[], int num_of_F, int pages[], int num_of_P)
{
	int sum_PF = 0;
	int next_check = 0;
	for (size_t i = 0; i < num_of_P; i++)
	{
		if (exist(frames, num_of_F, pages[i]))
			continue;
		else
		{
			//given second chance..
			while (frames[next_check].reference_bit == true)
			{
				frames[next_check].reference_bit = false;
				next_check = (next_check + 1) % num_of_F;
			}
			frames[next_check].value = pages[i];
			next_check = (next_check + 1) % num_of_F;
			sum_PF++;
		}
	}
	return sum_PF;
}

void main()
{
	frame frams_4[4];
	frame frams_3[3];
	int pages[16] = {1,2,3,4,2,1,5,6,2,1,2,3,6,6,3,4};
	cout << "for the following pages request\n" <<
		"{1,2,3,4,2,1,5,6,2,1,2,3,6,6,3,4}\n"
		"the number of page-fault when we ran second chance with 4 frames:\n"
		<< sum_of_PF(frams_4, 4, pages, 16) << endl <<
		"and with 3 frames:\n"
		<< sum_of_PF(frams_3, 3, pages, 16) << endl;
	
	system("pause");
}