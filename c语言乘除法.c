#include"stdint.h"
#include"stdio.h"
uint32_t mul_dis(uint32_t r_mula,\
uint16_t r_mulb);
typedef union
{
	uint32_t All;
	struct{
	
	uint16_t r_quotient;//商数
	uint16_t r_remainder;//余数
	}Part;
}division_result;
division_result r_division_resulta;

void div_dis(uint32_t r_divident,\
uint16_t r_divisor);
void main()
{
	//
	uint32_t r_a4;
	uint16_t r_b2;
	uint16_t r_quo2,r_rem2;
	
	r_a4=327490;
	r_b2=7586;
	//r_a4=45;
	//r_b2=2;
	r_quo2=r_a4/r_b2;
	r_rem2=r_a4%r_b2;
	div_dis(r_a4,r_b2);//除法
	if(r_quo2==\
	r_division_resulta.Part.r_quotient\
	&&r_rem2==r_division_resulta.Part.\
	r_remainder)
	{
		printf("计算正确:\n");
		printf("计算结果%d/%d=%d\n",\
		r_a4,r_b2,r_quo2);
		printf("计算结果%d%%%d=%d\n",\
		r_a4,r_b2,r_rem2);
	}
	else
	{
		printf("计算错误\n");
		printf("正确结果除数=%d\n",\
		r_quo2);
		printf("错误结果除数=%d\n",\
		r_division_resulta.Part.r_quotient);
		printf("正确结果余数=%d\n",\
		r_rem2);
		printf("错误结果余数=%d\n",\
		r_division_resulta.Part.r_remainder);
		
	}
	
}
uint32_t mul_dis(uint32_t r_mul4,\
uint16_t r_mul2)
//r_mul4_a=r_mul4*r_mul2
{
	uint16_t r_shift_count;
	uint32_t r_mul4_a;
	uint8_t f_r_buf0;
	r_mul4_a=0;
	for(r_shift_count=0;\
	r_shift_count<16;\
	r_shift_count++)
	{
		r_mul4_a<<=1;//涔樼Н宸︾Щ
		f_r_buf0=0;
		if(r_mul2&0x8000)
		{
			f_r_buf0=1;
		}
		r_mul2<<=1;//r_mul1宸︾Щ
		if(f_r_buf0)
		{
			r_mul4_a+=r_mul4;
		}
		
	}
	return r_mul4_a;
}
typedef union
{
	uint32_t All;
	struct{
	
	uint16_t r_quotient;//商数
	uint16_t r_remainder;//余数
	}Part;
}division_result;
division_result r_division_resulta;
void div_dis(uint32_t r_divident,\
uint16_t r_divisor)
{
	r_division_resulta.All=0;
	uint32_t r_bufa=0;
	uint8_t r_shift_count;
	uint8_t f_r_buf0;
	for(r_shift_count=0;\
	r_shift_count<32;r_shift_count++)
	{
		r_bufa<<=1;
		f_r_buf0=0;
		if(r_divident&0x80000000)
		{
			f_r_buf0=1;
		}
		r_divident<<=1;
		if(f_r_buf0)
		{
			r_bufa+=1;
		}
		if(r_bufa>=r_divisor)
		{
			r_division_resulta.\
			Part.\
			r_quotient<<=1;
			r_division_resulta.\
			Part.\
			r_quotient+=1;
			r_bufa-=r_divisor;
		}
		else
		{
			r_division_resulta.\
			Part.\
			r_quotient<<=1;
		}
	}
	r_division_resulta.\
	Part.\
	r_remainder=r_bufa;
}
