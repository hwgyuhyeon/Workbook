#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
#include "InputUtil.h"
#include "IOInterface.h"
using namespace std;

class Subject : public IOInterface {
protected:
	string m_name; //과목이름
	int m_hakjum; //과목학점
	string m_grade; //과목등급
	float m_GPA; //과목평점

public:
	Subject(); //멤버변수 초기화
	Subject(string subname, int hakjum, string grade); // 인자값으로 멤버변수 초기화
	Subject(const Subject& sub); //다른 Student클래스의 멤버변수 값으로 초기화
	~Subject();

	void InputData() { //멤버변수 값 입력
		cout << "교과목명: ";
		InputUtil::InputValue(m_name); //정보 수정 시 중복을 막기 위해 초기화 x
		cout << "과목학점수: ";
		InputUtil::InputValue(m_hakjum);
		cout << "과목등급(A+ ~ F): ";
		InputUtil::InputValue(m_grade);
		CalcGPA(); //평점 계산 후 구조체에 포함
		cout << "\n";
	};
	static void PrintTitle();//멤버변수에 대한 title text 출력
	void PrintData() const { //멤버변수 값 출력
		cout.width(12);
		cout << m_name;
		cout.width(9);
		cout << m_hakjum;
		cout.width(17);
		cout << m_grade;
		cout.width(10);
		cout << m_GPA << "\n";
	};
	void CalcGPA() { //평점 계산
		float grade = 0;

		//평점 변환
		if (m_grade == "A+" || m_grade == "A" || m_grade == "A0") {
			grade += 4;
			if (m_grade == "A+") {
				grade += 0.5;
			}
		}
		else if (m_grade == "B+" || m_grade == "B" || m_grade == "B0") {
			grade += 3;
			if (m_grade == "B+") {
				grade += 0.5;
			}
		}
		else if (m_grade == "C+" || m_grade == "C" || m_grade == "C0") {
			grade += 2;
			if (m_grade == "C+") {
				grade += 0.5;
			}
		}
		else if (m_grade == "D+" || m_grade == "D" || m_grade == "D0") {
			grade += 1;
			if (m_grade == "D+") {
				grade += 0.5;
			}
		}
		else {
			grade = 0;
		}

		//변환한 학점으로 평점내서 저장(리턴)
		grade *= m_hakjum;
		m_GPA = grade;
	};
	void Modify() { //과목정보 수정
		cout << "\n\n* 수정할 '"<< m_name <<"' 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		cout << "교과목명: ";
		InputUtil::InputValue(m_name); //정보 수정 시 중복을 막기 위해 초기화 x
		cout << "과목학점수: ";
		InputUtil::InputValue(m_hakjum);
		cout << "과목등급(A+ ~ F): ";
		InputUtil::InputValue(m_grade);
		CalcGPA(); //평점 계산 후 구조체에 포함
		cout << "\n";
	}

	//접근자 함수
	string GetName() const {
		return m_name;
	};
	int GetHakjum() const {
		return m_hakjum;
	};
	string GetGrade() const {
		return m_grade;
	};
	float GetGPA() const {
		return m_GPA;
	};
};

/* 정적 멤버 함수 */
void Subject::PrintTitle() { //멤버변수에 대한 title text 출력
	cout << "-----------------------------------------------------\n";
	cout << "   교과목명     학점수       등급         평점\n";
	cout << "-----------------------------------------------------\n";
};

/* 생성자와 소멸자 */
Subject::Subject() { //멤버변수 초기화
	cout << "* 과목 생성자 호출 *\n";
	m_name = " ";
	m_hakjum = 0;
	m_grade = " ";
	m_GPA = 0.0f;
};

Subject::Subject(string subname, int hakjum, string grade) { //인자값으로 멤버변수 초기화
	cout << "* 과목 생성자 호출 *\n";
	m_name = subname;
	m_hakjum = hakjum;
	m_grade = grade;
	CalcGPA();
};

Subject::Subject(const Subject& sub) { //다른 Student클래스의 멤버변수 값으로 초기화
	cout << "* 과목 생성자 호출 *\n";
	this->m_name = sub.m_name;
	this->m_hakjum = sub.m_hakjum;
	this->m_grade = sub.m_grade;
	this->m_GPA = sub.m_GPA;
}

Subject::~Subject() {
	cout << "* 과목 소멸자 호출 *\n";
};
