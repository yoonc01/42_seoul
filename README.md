# 42 Seoul Projects

## 📋 소개
42 Seoul 교육과정에서 수행한 프로젝트 모음입니다. C/C++ 프로그래밍의 기초부터 시스템 프로그래밍, 알고리즘, 네트워크까지 다양한 분야의 실습 프로젝트를 포함하고 있습니다.

## 📂 프로젝트 목록

### 기초 프로그래밍
- **[C00 - C13](./C00)**
  - C 언어 기본 문법 및 로직 학습을 위한 과제 시리즈
  - 주요 학습 내용: 포인터, 문자열 처리, 메모리 관리, 재귀 함수
  - 데이터 구조와 알고리즘 기초 구현

- **[CPP00 - CPP04](./CPP00)**
  - C++ 객체지향 프로그래밍 심화 학습
  - 핵심 개념: 캡슐화, 상속, 다형성, 템플릿
  - Orthodox Canonical Form 구현
  - 연산자 오버로딩 및 예외 처리

### 시스템 프로그래밍
- **[Born2beroot](./Born2beroot)**
  - 가상머신을 활용한 서버 구축
  - 시스템 모니터링 및 보안 설정
  - 방화벽, SSH, 사용자 관리 실습

- **[Minishell](./Minishell)**
  - bash 쉘의 주요 기능 구현
  - 프로세스 관리, 파이프, 리다이렉션
  - 환경변수 및 시그널 처리
  - [Minishell 레포지토리리](https://github.com/yoonc01/Re_minishell)

### 네트워크 & 동시성
- **[Minitalk](./Minitalk)**
  - UNIX 시그널을 이용한 클라이언트-서버 통신
  - 비트 연산을 통한 데이터 전송 구현

- **[Net_Practice](./Net_Practice)**
  - TCP/IP 네트워크 기본 개념 학습
  - 서브넷 마스크 및 라우팅 설정
  - [상세 학습 내용 블로그](https://velog.io/@yoonc01/series/42-netpractice)

- **[Philosophers](./Philosophers)**
  - 식사하는 철학자 문제 구현
  - 멀티스레드 프로그래밍
  - 뮤텍스와 세마포어를 활용한 동기화

### 알고리즘 & 자료구조
- **[BSQ](./BSQ)**
  - 동적 프로그래밍을 활용한 최대 정사각형 찾기
  - 2D 배열 처리 및 최적화

- **[Push_Swap](./Push_Swap)**
  - 스택 기반 정렬 알고리즘 구현
  - 최소 연산으로 데이터 정렬하기
  - 알고리즘 최적화 및 성능 분석

### 라이브러리 구현
- **[Libft](./Libft)**
  - C 표준 라이브러리 함수 재구현
  - 문자열, 메모리, 리스트 처리 함수 구현
  - 자료구조 기초 구현

- **[Ft_printf](./Ft_printf)**
  - printf 함수의 핵심 기능 구현
  - 가변 인자 처리
  - 서식 지정자 파싱 및 처리

- **[GNL (Get Next Line)](./GNL)**
  - 파일 디스크립터로부터 행 단위 읽기
  - 정적 변수를 활용한 상태 관리
  - 메모리 누수 관리

### 그래픽스
- **[Fract-ol](./Fract-ol)**
  - MinilibX 라이브러리를 활용한 프랙탈 렌더링
  - 줄리아 셋, 만델브로트 셋 구현
  - 이벤트 처리 및 최적화

### 팀 프로젝트
- **[Rush00 - Rush02](./Rush00)**
  - 팀 협업을 통한 알고리즘 구현
  - Git을 활용한 버전 관리
  - 코드 리뷰 및 품질 관리

## 🛠️ 기술 스택
- **핵심 언어**: C, C++
- **개발 도구**: 
  - Git: 버전 관리
  - Makefile: 프로젝트 빌드 자동화
  - Bash: 쉘 스크립팅
- **개발 환경**: Linux, macOS

## 🚀 실행 방법
1. 프로젝트 클론
```bash
git clone https://github.com/yoonc01/42_seoul.git
cd 42_seoul
```
2. 프로젝트 빌드 및 실행
```
cd [project_directory]
make
./[executable_name]
```
