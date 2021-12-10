// ex-1-main.cpp
#include <iostream>
#include<vector>
using namespace std;
#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B

/* --------------------------------------------------------------- */
/*
* gcd
*
* �^����ꂽ������ a �� d�ɑ΂��āA�ő���񐔂�Ԃ�
*
*/
/* -------------------------------------------------------------- */
int gcd(int a, int b)
{
	if (a%b == 0)
	{
		return(b);
	}else{
		return(gcd(b, a%b));
	}
}
/* --------------------------------------------------------------- */
/*
* is_prime
*
* �^����ꂽ������ x �ɑ΂��āA�f�����ǂ����𔻒肷��
*
*/
/* -------------------------------------------------------------- */
bool is_prime(unsigned int x) {
	int flag = 0;
	if (x < 2) {
		return false;
	}
	else if (x == 2) {
		return true;
	}
	else if (x % 2 == 0) {
		return false;
	}

	double sqx = sqrt(x);
	for (int i = 3; i <= sqx; i += 2) {
		if (x%i == 0) {
			return false;
		}
	}
	return true;
}
/* --------------------------------------------------------------- */
/*
* nth_prime
*
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ̑f����Ԃ��B
* �K�؂ȓ��͂łȂ��ꍇ��-1��Ԃ��B
*
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	if (a == 0 || d== 0 || n == 0) {
		return -1;
	}
	if (a > 65535 || d > 65535 || n > 65535) {
		return -1;
	}
	if (!(gcd(a,d) == 1)) {
		return -1;
	}
	int num = a;
	int count = 0;//num���f���ł����1�C���N�������g����B
	while (num < 1000000) {
		if (is_prime(num) == true) {
			count++;
		}
		if (count == n) {
			return num;
		}
		num += d;
	}
}

int main() {
	std::cout << nth_prime(367, 186, 151) << std::endl;
	std::cout << nth_prime(179, 10, 203) << std::endl;
	std::cout << nth_prime(271, 37, 39) << std::endl;
	std::cout << nth_prime(103, 230, 1) << std::endl;
	std::cout << nth_prime(27, 104, 185) << std::endl;
	std::cout << nth_prime(253, 50, 85) << std::endl;
	std::cout << nth_prime(1, 1, 1) << std::endl;
	std::cout << nth_prime(9075, 337, 210) << std::endl;
	std::cout << nth_prime(307, 24, 79) << std::endl;
	std::cout << nth_prime(331, 221, 177) << std::endl;
	std::cout << nth_prime(259, 170, 40) << std::endl;
	std::cout << nth_prime(269, 58, 102) << std::endl;
	// �ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B

	//�K�؂ȓ��͏o�Ȃ��ꍇ
	std::cout << nth_prime(-367, 186, 151) << std::endl;
	std::cout << nth_prime(367, -186, 151) << std::endl;
	std::cout << nth_prime(367, 186, -151) << std::endl;
	//���͒l�Ƀ}�C�i�X�����Ă���
	std::cout << nth_prime(0, 10, 203) << std::endl;
	std::cout << nth_prime(17, 0, 203) << std::endl;
	std::cout << nth_prime(17, 10, 0) << std::endl;
	//���͒l��0�������Ă���
	std::cout << nth_prime(2, 222, 39) << std::endl;
	//a��d���݂��ɑf�łȂ�
        cin.get();
        return 0;
}