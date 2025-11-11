<div id="top"></div>

<h1 align="center">🎮 WinAPI Isaac Project — 2D Roguelike (C++/Win32)</h1>
<p align="center">
  <b>Win32 API + GDI</b>로 구현한 더블버퍼링 2D 로그라이크 액션 게임<br/>
  8방향 이동 · 4방향 공격 · 적 AI · 랜덤 방 생성 · 체력/아이템 시스템
</p>
<p align="center">
  <a href="https://youtu.be/BAIw8pGOYqg?si=YBMTaI8VVswIkmpp" target="_blank" rel="noreferrer">▶ YouTube 데모 보기</a>
</p>

<hr/>

<!-- TL;DR -->
<h2 id="tldr">🧭 TL;DR (빠른 소개)</h2>
<ul>
  <li><b>엔진 없이</b> 순수 <b>C++/Win32 API</b>로 루프·렌더링(GDI)·입력·사운드 직접 구현</li>
  <li><b>핵심 기능</b>: 8방향 이동, 4방향 공격, 적 AI, 랜덤 방/씬 전환, 체력 UI, 기본 아이템</li>
  <li><b>설계</b>: Game/Scene/Resource Manager + <code>Scene</code> 추상화 + 싱글톤/상태/프로토타입 패턴</li>
  <li>자세한 기술/설계는 아래 <a href="#full">📚 원문 상세</a>에 모두 포함 (접기/펼치기)</li>
</ul>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Table of Contents -->
<h2 id="toc">📚 Table of Contents</h2>
<ol>
  <li><a href="#about">프로젝트 소개</a></li>
  <li><a href="#demo">데모 & 스크린샷</a></li>
  <li><a href="#features">주요 특징</a></li>
  <li><a href="#stack">개발 환경 & 기술 스택 (요약)</a></li>
  <li><a href="#structure">프로젝트 구조</a></li>
  <li><a href="#controls">조작 방법</a></li>
  <li><a href="#run">실행 방법 (요약)</a></li>
  <li><a href="#design">설계 개요 (요약)</a></li>
  <li><a href="#collision">충돌 & 수학 유틸 (요약)</a></li>
  <li><a href="#learned">학습 내용 (요약)</a></li>
  <li><a href="#full">📚 상세 내용 (전체 본문, 접기/펼치기)</a></li>
</ol>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- About -->
<h2 id="about">1) 프로젝트 소개</h2>
<p>
  <b>The Binding of Isaac</b> 스타일의 2D 로그라이크를 <b>Win32 API</b>로 직접 구현했습니다.
  윈도우 생성 → 메시지 루프 → 더블 버퍼링 렌더링 → 입력/사운드 처리까지
  <b>저수준 흐름</b>을 모두 C++로 다룹니다.
</p>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Demo -->
<h2 id="demo">2) 데모 & 스크린샷</h2>
<ul>
  <li>🎥 <b>YouTube</b>:
    <a href="https://youtu.be/BAIw8pGOYqg?si=YBMTaI8VVswIkmpp" target="_blank" rel="noreferrer">https://youtu.be/BAIw8pGOYqg?si=YBMTaI8VVswIkmpp</a>
  </li>
</ul>
<div>
  <img alt="ingame-1" src="https://github.com/user-attachments/assets/dd6ded39-ae05-426e-bc2b-e3d2b62c2ea1" style="max-width:100%;height:auto;"/>
</div>
<div>
  <img alt="ingame-2" src="https://github.com/user-attachments/assets/85731382-3d9e-4852-ad93-17a84a3619dd" style="max-width:100%;height:auto;"/>
</div>
<p><i>※ GitHub README는 정책상 인라인 동영상 재생이 제한될 수 있습니다. 링크로 시청해주세요.</i></p>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Features -->
<h2 id="features">3) 🚀 주요 특징</h2>
<ul>
  <li>🏃 8방향 이동 & 애니메이션</li>
  <li>🎯 4방향 발사(플레이어 탄환)</li>
  <li>👾 적 생성 & 기본 AI 패턴</li>
  <li>🚪 방/씬 전환 시스템</li>
  <li>❤️ 체력 UI & 💎 기본 아이템 시스템</li>
  <li>🧰 간단 맵툴</li>
</ul>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Stack (summary) -->
<h2 id="stack">4) 🧱 개발 환경 & 기술 스택 (요약)</h2>
<ul>
  <li><b>Language</b>: C/C++ (C++17)</li>
  <li><b>API</b>: Win32 API (WinAPI), GDI/GDI+</li>
  <li><b>IDE</b>: Visual Studio 2019/2022</li>
  <li><b>Graphics</b>: GDI 더블 버퍼링(Back Buffer + BitBlt)</li>
  <li><b>Audio</b>: WinMM (PlaySound/MCI)</li>
</ul>
<p><a href="#full">➡ 상세 스택으로 이동</a></p>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Structure -->
<h2 id="structure">5) 📁 프로젝트 구조</h2>
<pre><code>plaintext
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
</code></pre>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Controls -->
<h2 id="controls">6) 🎮 조작 방법</h2>
<ul>
  <li><b>이동</b>: <code>W / A / S / D</code></li>
  <li><b>공격</b>: <code>↑ / ← / ↓ / →</code> (방향키)</li>
  <li><b>종료</b>: <code>ESC</code></li>
</ul>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Run (summary) -->
<h2 id="run">7) 💻 실행 방법 (요약)</h2>
<p><b>요구사항</b></p>
<ul>
  <li>Windows 10 이상</li>
  <li>Visual Studio 2019 이상 (C++ 개발 도구)</li>
</ul>

<p><b>빌드 & 실행</b></p>
<pre><code>bash
git clone https://github.com/yourusername/WinAPI_Isaac_Project.git
</code></pre>
<ol>
  <li>Visual Studio에서 <code>WinAPI_Isaac_Project.sln</code> 열기</li>
  <li>구성: <b>Debug</b> / 플랫폼: <b>Win32(x86)</b> 확인</li>
  <li><b>Build</b> → <b>F5</b> 실행 (또는 출력 폴더의 exe 실행)</li>
</ol>
<p><a href="#full">➡ 실행 상세로 이동</a></p>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Design (summary) -->
<h2 id="design">8) 🧩 설계 개요 (요약)</h2>
<ul>
  <li><b>OOP 계층</b>: <code>GameObject</code>(위치/충돌 공통) ← <code>Player/Enemy/Bullet</code></li>
  <li><b>Manager</b>: <code>GameManager</code>(루프/전역), <code>SceneManager</code>(상태/씬), <code>ResourceManager</code>(이미지/사운드)</li>
  <li><b>패턴</b>: 싱글톤(전역 접근), 상태(씬 전환), 프로토타입/팩토리(반복 생성 최적화, 필요 시 풀링)</li>
  <li><b>리소스</b>: 중앙집중 로딩/캐싱 → 재사용, 종료 시 일괄 해제(메모리/GDI 누수 방지)</li>
  <li><b>렌더링</b>: 백버퍼 DC에 그린 뒤 화면으로 <code>BitBlt</code> (플리커 최소화)</li>
</ul>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Collision (summary) -->
<h2 id="collision">9) ⚙️ 충돌 & 수학 유틸 (요약)</h2>
<ul>
  <li><b>충돌</b>: AABB 사각 충돌 기본, 일부 원형(반경) 판정 보조</li>
  <li><b>최적화</b>: 활성 객체만 검사, 충돌 후 즉시 삭제 대신 마킹 → 프레임 말에 정리</li>
  <li><b>유틸</b>: <code>Vector2</code>, <code>Distance/Clamp/Lerp</code>, 경계 체크, 난수, 고해상도 타이머(<code>QueryPerformanceCounter</code>)</li>
</ul>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Learned -->
<h2 id="learned">10) 📖 학습 내용 (요약)</h2>
<ul>
  <li>Win32 <b>메시지 루프/윈도우 라이프사이클</b></li>
  <li><b>GDI 더블 버퍼링</b>과 스프라이트 블리팅</li>
  <li><b>객체지향 설계</b>(SRP/캡슐화/다형성)와 매니저 구조</li>
  <li><b>충돌 감지/시간기반 업데이트</b>(deltaTime)</li>
  <li><b>리소스/메모리 관리</b>(중앙집중 캐싱, 해제 규칙)</li>
</ul>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Full Detail (merged long content) -->
<h2 id="full">11) 📚 상세 내용 (전체 본문, 접기/펼치기)</h2>
<details open>
  <summary><b>클릭하여 접기/펼치기</b> — 기술 스택/설계/패턴/충돌/씬/빌드 상세 포함</summary>
  <br/>

  <!-- 사용 기술 스택 -->
  <h3 id="full-stack">A. 사용 기술 스택</h3>
  <ul>
    <li><b>언어</b>: C++ (표준 C++17 준수). 메모리 관리 등 대부분을 수동으로 처리하여 퍼포먼스와 저수준 제어에 집중.</li>
    <li><b>플랫폼 &amp; API</b>: Win32 API 기반 개발. 윈도우 생성, 메시지 루프, GDI 2D 렌더링, 키보드 입력(예: <code>WM_KEYDOWN</code>), 타이머, 더블 버퍼링 등 직접 구현.</li>
    <li><b>그래픽</b>: <b>GDI</b>(Graphics Device Interface)로 2D 블리팅 및 그리기. <code>BitBlt</code>로 백버퍼에 스프라이트를 그린 후 화면에 출력하는 더블 버퍼링 (DirectX/OpenGL 미사용).</li>
    <li><b>오디오</b>: WinAPI 멀티미디어 API(<code>PlaySound</code>, MCI)로 WAV 재생. 외부 사운드 엔진 없이 Windows 기본 함수 사용.</li>
    <li><b>IDE &amp; 빌드</b>: Visual Studio 2019/2022. Win32 (x86) Debug/Release 구성으로 Windows 실행 파일(.exe) 생성.</li>
  </ul>

  <!-- 객체지향 설계 분석 -->
  <h3 id="full-oop">B. 객체지향 설계 분석</h3>
  <ul>
    <li><b>클래스 계층 구조</b>: <code>GameObject</code> 추상 기반(위치/속도/충돌 공통) ← <code>Player</code>, <code>Enemy</code>, <code>Bullet</code> 등 상속. 다형성으로 일관된 업데이트/렌더링.</li>
    <li><b>캡슐화</b>: 멤버는 <code>private</code> 중심, 게터/세터 또는 퍼블릭 메서드로만 접근. 예) <code>Player::TakeDamage(int)</code>.</li>
    <li><b>SRP</b>: <code>Player</code>(이동/공격), <code>Enemy</code>(AI), <code>SceneManager</code>(화면 전환), <code>GameManager</code>(게임 전체 흐름) 등 단일 책임.</li>
    <li><b>추상화</b>: <code>Scene</code> 추상 클래스로 상태 전환 로직을 종류와 무관하게 동작. <code>Enemy</code>는 하위 파생형으로 패턴 확장.</li>
    <li>요약: WinAPI 호출을 C++ 메서드로 캡슐화, 매니저 구조/패턴으로 전역 상태와 전이를 효율 처리.</li>
  </ul>

  <!-- 주요 클래스 역할 -->
  <h3 id="full-classes">C. 주요 클래스 역할 설명</h3>
  <ul>
    <li><b>GameManager</b>: 싱글톤. 윈도우 초기화, 게임 루프, 전역 시간/설정, 리소스 로딩/종료 관리 (<code>Init()</code>, <code>Run()</code>).</li>
    <li><b>SceneManager</b>: 싱글톤. 활성 <code>Scene*</code> 보관, <code>ChangeScene(SceneID)</code>, 루프 내 <code>Update/Render</code> 위임.</li>
    <li><b>Scene</b> (추상): <code>Update()</code>, <code>Render()</code>, <code>OnEnter()</code>, <code>OnExit()</code> 규약.<br/>
      <ul>
        <li><b>MenuScene</b>: 시작 화면/입력 → GameScene 전환.</li>
        <li><b>GameScene</b>: 플레이/적/탄환 생성 및 관리, 조건 시 GameOver 등으로 전환.</li>
      </ul>
    </li>
    <li><b>Player</b>: 입력 처리, 이동/공격, HP/속도/공격력/방향 상태, 충돌 시 <code>TakeDamage()</code>.</li>
    <li><b>Enemy</b>: 추적형/발사형 등 AI 구현, 피격/체력 0 시 제거.</li>
    <li><b>Bullet (Tear)</b>: 위치/속도/공격력, 경계 외/충돌 시 소멸.</li>
    <li><b>ResourceManager</b>: 이미지/사운드 중앙 관리(맵 캐싱). <code>LoadImage/GetImage</code> 등. 종료 시 일괄 해제.</li>
    <li><b>Utils/Math</b>: 충돌/거리/각도/난수/보간/타이머 등 공용 유틸.</li>
    <li>(선택) <b>InputManager</b>, <b>UIManager</b>: 입력 상태/HP 하트·점수 UI 등.</li>
  </ul>

  <!-- 리소스 관리 -->
  <h3 id="full-res">D. 리소스 관리 방식</h3>
  <ul>
    <li><b>이미지 로딩</b>: 시작/씬 초기화 시 <code>LoadImage/LoadBitmap</code>로 <code>HBITMAP</code> 로드→맵 캐싱→재사용.</li>
    <li><b>사운드</b>: 효과음 즉시 재생(<code>PlaySound</code>), BGM 루프(MCI). 키-리소스 매핑으로 호출 간소화.</li>
    <li><b>해제</b>: 종료 시 <code>DeleteObject</code>, <code>PlaySound(NULL,...)</code> 등으로 누수 방지. 백버퍼 DC/비트맵 재사용 후 해제.</li>
    <li><b>의존 역전</b>: 오브젝트는 파일을 직접 로드하지 않고 매니저에서 핸들을 받아 사용.</li>
  </ul>

  <!-- 디자인 패턴 -->
  <h3 id="full-patterns">E. 사용한 디자인 패턴</h3>
  <ul>
    <li><b>싱글톤</b>: Game/Scene/Resource Manager 등 전역 관리.</li>
    <li><b>상태(State)</b>: <code>Scene</code> 추상 + SceneManager로 메뉴/플레이/오버 전환.</li>
    <li><b>프로토타입</b> (&amp; 풀링): 적/탄환 반복 생성 시 복제 기반 최적화.</li>
    <li>(확장) 옵저버: HP 변화 이벤트→UI 반영. 팩토리: ID/문자열로 객체 생성.</li>
  </ul>

  <!-- 충돌/수학 유틸 (상세) -->
  <h3 id="full-collision">F. 충돌 처리 &amp; 수학 유틸리티 구성</h3>
  <ul>
    <li><b>충돌</b>: AABB 기본, 일부 원형 판정. 빈번 호출 대비 활성 객체만 검사, 삭제 마킹 후 프레임 말 정리.</li>
    <li><b>벡터/수학</b>: <code>Vector2</code> 연산, 각도→단위 벡터, 거리/보간/Clamp/경계 체크.</li>
    <li><b>난수</b>: C++ <code>&lt;random&gt;</code> 유틸로 드랍/스폰 등 확률 처리.</li>
    <li><b>타이머</b>: <code>QueryPerformanceCounter</code> 기반 <code>deltaTime</code>으로 프레임 독립 이동.</li>
  </ul>

  <!-- 씬 관리 -->
  <h3 id="full-scenes">G. 씬 관리 방식 및 전환 처리</h3>
  <ol>
    <li><b>구성</b>: <code>Scene</code> 추상 + <code>MenuScene</code>, <code>GameScene</code> (+<i>GameOver/Pause</i> 확장 가능).</li>
    <li><b>전환</b>: <code>ChangeScene()</code> → <code>OnExit()</code> → 삭제 → 새 씬 생성 → <code>OnEnter()</code> → 포인터 교체.</li>
    <li><b>루프 연동</b>: <code>Update/Render</code> 위임, 필요 시 프레임 보정/Sleep.</li>
    <li><b>안정성</b>: 연속 전환 방지 플래그, 스택형 Pause 확장 가능.</li>
  </ol>

  <!-- 스크린샷 (설명 자리) -->
  <h3 id="full-screens">H. 스크린샷</h3>
  <p>주인공/적/UI 요소 포함 예시 화면. (상단 이미지 참고 / 추가 샷 가능)</p>

  <!-- 실행 상세 -->
  <h3 id="full-run">I. 빌드 및 실행 방법 (상세)</h3>
  <ol>
    <li><b>소스 받기</b>: 저장소를 클론하거나 ZIP 다운로드.</li>
  </ol>
  <pre><code>bash
git clone https://github.com/jaeseung9/WinAPI_Isaac_Project.git
</code></pre>
  <ol start="2">
    <li><b>솔루션 열기</b>: Visual Studio 2019+에서 <code>WinAPI_Isaac_Project.sln</code> 오픈.</li>
    <li><b>환경</b>: Win10 SDK 자동 설정 권장.</li>
    <li><b>구성/플랫폼</b>: <b>Debug</b> / <b>Win32(x86)</b> 권장 (Release 선택 가능).</li>
    <li><b>빌드/실행</b>: <b>Build</b> → <b>F5</b> 또는 출력 폴더 .exe 실행.</li>
    <li><b>종료</b>: 창 닫기([X]) 또는 인게임 Exit. 디버그 모드에서 누수 경고 없으면 해제 정상.</li>
    <li><b>주의</b>: Windows 전용. WAV 코덱 기본 제공. x64 OS에서도 x86 실행 정상.</li>
  </ol>

  <p><a href="#top">⬆ Back to top</a></p>
</details>
