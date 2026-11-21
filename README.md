# C-Programming-Project

## 1. 프로젝트 제목 및 목적

프로젝트 제목: Private English Dictionary (나만의 영단어장)

프로젝트 목적: 평소 영어 공부를 하며 직접 영단어장을 만들어 사용해 왔는데, 정리한 단어장만으로는 학습 중 불편함을 느꼈습니다.

이를 해결하기 위해 단어 저장 + 랜덤 퀴즈 기능을 추가하여 학습 효율을 높이는 프로그램을 만들기로 했습니다.

## 학번 이름

수행방식: 개인

소속: 소프트웨어 A반

학번: 202605010

이름: 박재웅

## 주요기능
  Add Word	영단어와 뜻을 입력해 단어장에 추가하고, 즉시 파일에 저장
  
  Show Words	지금까지 저장된 단어들을 번호와 함께 한눈에 출력
  
  Quiz	단어장에서 N개의 문제를 랜덤으로 출제하고 점수를 채점
  
  Exit	프로그램 종료

  -추가동작-
  
  프로그램 시작 시 dictionary.txt에서 기존 단어를 자동으로 불러옴
  
  단어가 100개를 넘으면 The dictionary is full. 메시지 출력
  
  단어가 없을 때 조회/퀴즈를 선택하면 안내 메시지 출력 (오류 처리)
  
  메뉴에 없는 번호를 입력하면 Invalid input. 출력 후 다시 메뉴로 복귀
  

## 사용한 C 문법
  기본 문법	변수, 자료형(int, char), 연산자(%, ++, >=, ==, !=)
  
  입출력	printf(), scanf()
  
  조건문	if / else, switch - case
  
  반복문	for, while, do-while
  
  배열·문자열	char 배열, 구조체 배열(Word words[MAX]), strcmp()
  
  사용자 정의 함수	load_words, save_words, add_word, show_words, quiz (5개)
  
  구조체 (심화)	typedef struct로 Word 자료형 정의
  
  파일 입출력 (심화)	fopen, fscanf, fprintf, fclose
  
  난수	rand(), srand(), time()
  
  전처리기	#define MAX 100, #include <stdio.h> <stdlib.h> <string.h> <time.h>

## 실행 방법
  실행 후 메뉴 선택
  
## 실행화면
    ===== My English Dictionary =====
	
1. Add Word
   
2. Show Words

3. Quiz

0. Exit

-> 숫자로 입력 후 단어를 추가하거나, 단어장을 확인, 퀴즈를 풀 수 있음.
  
## AI 활용 내용

사용 AI 도구: ChatGPT / Claude

활용 내용: 코드에서 사용한 헤더파일, do-while, srand 등 개념 이해에 활용, 오류 해결 및 코드 동작 원리 확인에 활용

## 어려움 및 해결 방법

문제	프로그램을 종료하면 등록한 단어가 모두 사라짐

원인	단어가 전역배열(메모리)에만 저장되어 있어 종료 시 함께 삭제됨

해결	파일 입출력(fopen, fprintf, fscanf)을 사용해 dictionary.txt에 저장하고, 프로그램 실행 시 load_words()로 불러오도록 구현.

## 개발 소감
AI가 코딩에 매우 유용하다는 것을 느꼈지만, 동시에 이용자가 코드를 이해하고 있어야 AI의 답변을 제대로 활용하고 검증할 수 있다는 점도 느꼈습니다.


