🎮 WinAPI Isaac Project
The Binding of Isaac 스타일의 로그라이크 게임을 Windows API를 사용하여 구현한 프로젝트입니다.
📺 Demo
<img width="842" height="624" alt="image" src="https://github.com/user-attachments/assets/dd6ded39-ae05-426e-bc2b-e3d2b62c2ea1" />
<img width="862" height="638" alt="image" src="https://github.com/user-attachments/assets/85731382-3d9e-4852-ad93-17a84a3619dd" />

▶️ 게임 플레이 영상 보기
https://youtu.be/BAIw8pGOYqg?si=YBMTaI8VVswIkmpp
🎯 프로젝트 소개
The Binding of Isaac의 핵심 게임플레이를 Win32 API를 활용하여 구현한 2D 로그라이크 액션 게임입니다.
주요 특징

🏃 자유로운 8방향 이동 시스템
🎯 4방향 공격 메커니즘
👾 다양한 적 AI 패턴
🚪 무작위 방 생성 시스템
💎 아이템 및 파워업 시스템
❤️ 체력 관리 시스템

🛠️ 개발 환경

Language: C/C++
API: Win32 API (WinAPI)
IDE: Visual Studio
Graphics: GDI/GDI+

🎮 조작 방법
이동

W / A / S / D - 캐릭터 이동

공격

↑ / ← / ↓ / → (방향키) - 4방향 공격

기타

ESC - 게임 종료

---

## 📁 프로젝트 구조
```plaintext
WinAPI_Isaac_Project/
├── src/
│   ├── main.cpp                # 메인 진입점
│   ├── Game/
│   │   ├── GameManager.cpp     # 게임 전체 관리
│   │   ├── SceneManager.cpp    # 씬 전환 관리
│   │   └── ResourceManager.cpp
│   ├── Object/
│   │   ├── Player.cpp          # 플레이어 클래스
│   │   ├── Enemy.cpp           # 적 클래스
│   │   ├── Projectile.cpp      # 투사체 클래스
│   │   └── Item.cpp            # 아이템 클래스
│   ├── Scene/
│   │   ├── TitleScene.cpp
│   │   ├── GameScene.cpp
│   │   └── ResultScene.cpp
│   └── Utils/
│       ├── Collision.cpp       # 충돌 처리
│       └── Math.cpp            # 수학 유틸리티
├── Resources/
│   ├── Sprites/
│   ├── Sounds/
│   └── Data/
└── README.md
```


🎨 구현 기능
✅ 완성된 기능

 플레이어 이동 및 애니메이션
 4방향 발사 시스템
 적 생성 및 AI
 충돌 감지 시스템
 방 전환 시스템
 체력 UI
 기본 아이템 시스템
 맵툴
 
🚀 실행 방법
요구사항

Windows 10 이상
Visual Studio 2019 이상 (C++ 개발 환경)

빌드 및 실행

저장소 클론

bashgit clone https://github.com/yourusername/WinAPI_Isaac_Project.git

Visual Studio에서 솔루션 파일 열기

WinAPI_Isaac_Project.sln

빌드 구성 선택 (Debug/Release)

📚 학습 내용
이 프로젝트를 통해 다음을 학습했습니다:

Win32 API를 활용한 게임 루프 구현
GDI를 이용한 2D 그래픽 렌더링
게임 오브젝트 관리 및 디자인 패턴
충돌 감지 알고리즘
메모리 관리 및 최적화

🐛 알려진 이슈



👤 제작자
seojaeseung

GitHub: @yourusername
YouTube: 게임 개발 채널
