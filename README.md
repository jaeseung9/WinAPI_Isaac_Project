<div id="top"></div>

<!-- ──────────────────────────────────────────────────────────────────────────────
  Project Summary
──────────────────────────────────────────────────────────────────────────────── -->
<h2>📌 C++ WinAPI: 2D 아이작 모작 (WinAPI Isaac Project)</h2>

<ul>
  <li><b>개발 인원</b>: 1명</li>
  <li><b>개발 기간</b>: 2023.01.01 ~ 2023.02.01</li>
  <li>
    🔗 <b>포트폴리오 GitHub</b>:
    <a href="https://github.com/jaeseung9/WinAPI_Isaac_Project" target="_blank" rel="noreferrer">
      https://github.com/jaeseung9/WinAPI_Isaac_Project
    </a>
  </li>
  <li>
    🔗 <b>포트폴리오 Project Overview</b>:
    <a href="https://seungcoding.tistory.com/83" target="_blank" rel="noreferrer">
      https://seungcoding.tistory.com/83
    </a>
  </li>
  <li>
    🔗 <b>시연 영상</b>:
    <a href="https://youtu.be/BAIw8pGOYqg?si=Ogl8NDcPM4WBSVjN" target="_blank" rel="noreferrer">
      https://youtu.be/BAIw8pGOYqg?si=Ogl8NDcPM4WBSVjN
    </a>
  </li>
</ul>

<h3>✅ 주요 개발 내용</h3>
<ul>
  <li>C++과 WinAPI를 활용해 2D 게임 <b>‘아이작’ 모작</b>을 구현한 개인 프로젝트</li>
  <li><code>GameManager</code> / <code>SceneManager</code> / <code>ObjectManager</code> 중심의 <b>객체지향 구조</b> 설계</li>
  <li><code>Player</code>, <code>Monster</code>, <code>Bullet</code>, <code>Room</code> 등을 클래스로 분리하고 <b>이동·충돌·랜덤 맵 생성</b> 로직 구현</li>
  <li>WinAPI의 <b>GDI 기반 스프라이트 렌더링</b>, 애니메이션 처리 및 <b>FPS Lock</b>을 통한 프레임 제어</li>
</ul>

<h3>📚 학습 및 성과</h3>
<ul>
  <li><b>객체지향 설계 원칙</b>(OOP, SOLID)을 실습하며 클래스 기반 게임 구조를 설계·구현</li>
  <li><code>SceneManager</code> 패턴을 통한 <b>상태 전환</b> 및 씬 간 메모리/자원 관리 방식 학습</li>
  <li><b>포인터와 동적 할당</b>, 수명 관리 등 C++ 메모리 제어 기법을 실전 프로젝트에서 적용</li>
  <li>WinAPI의 <b>GDI 그래픽 처리</b>와 <b>이벤트 루프 구조</b>를 직접 구현하며 게임 루프의 전체 흐름 이해</li>
</ul>

<hr/>

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
  <li>자세한 기술/설계는 아래 <a href="#full">📚 상세 내용</a>에 포함 (접기/펼치기)</li>
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
  <li><a href="#insights">🌱 느낀점 (전체 본문, 접기/펼치기)</a></li>
  <li><a href="#credits">👏 크레딧 (전체 본문, 접기/펼치기)</a></li>
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
<p><i>※ README에는 사용 샷만 노출합니다.</i></p>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Features -->
<h2 id="features">3) 🚀 주요 특징</h2>
<ul>
  <li>🏃 8방향 이동 & 애니메이션</li>
  <li>🎯 4방향 발사(플레이어 탄환)</li>
  <li>👾 적 생성 & 기본 AI 패턴</li>
  <li>🚪 랜덤 방/씬 전환 시스템</li>
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
<details>
  <summary><b>클릭하여 펼치기</b> — 기술 스택/설계/패턴/충돌/씬/빌드 상세</summary>
  <br/>

  <!-- 사용 기술 스택 -->
  <h3 id="full-stack">A. 사용 기술 스택</h3>
  <ul>
    <li><b>언어</b>: C++ (표준 C++17 준수). 수동 메모리 관리로 퍼포먼스/저수준 제어.</li>
    <li><b>플랫폼 &amp; API</b>: Win32 API. 윈도우 생성, 메시지 루프, GDI 2D 렌더링, 키보드 입력(<code>WM_KEYDOWN</code>), 타이머, 더블 버퍼링 직접 구현.</li>
    <li><b>그래픽</b>: <b>GDI</b> 블리팅. <code>BitBlt</code> 기반 백버퍼 → 화면 더블 버퍼링 (DirectX/OpenGL 미사용).</li>
    <li><b>오디오</b>: WinMM (<code>PlaySound</code>, MCI)로 WAV 재생.</li>
    <li><b>IDE &amp; 빌드</b>: Visual Studio 2019/2022. Win32(x86) Debug/Release.</li>
  </ul>

  <!-- 객체지향 설계 분석 -->
  <h3 id="full-oop">B. 객체지향 설계 분석</h3>
  <ul>
    <li><b>클래스 계층</b>: <code>GameObject</code> 추상 기반 ← <code>Player</code>, <code>Enemy</code>, <code>Bullet</code>.</li>
    <li><b>캡슐화</b>: 내부 상태는 <code>private</code>, 퍼블릭 메서드/게터로만 제어.</li>
    <li><b>SRP</b>: <code>Player</code>(이동/공격), <code>Enemy</code>(AI), <code>SceneManager</code>(전환), <code>GameManager</code>(루프/전역).</li>
    <li><b>추상화</b>: <code>Scene</code> 추상으로 상태 전환을 타입과 분리.</li>
  </ul>

  <!-- 주요 클래스 역할 -->
  <h3 id="full-classes">C. 주요 클래스 역할</h3>
  <ul>
    <li><b>GameManager</b>: 싱글톤. 초기화/루프/자원 관리.</li>
    <li><b>SceneManager</b>: 싱글톤. <code>ChangeScene</code>, <code>Update/Render</code> 위임.</li>
    <li><b>Scene</b> (추상): <code>OnEnter/OnExit/Update/Render</code>. <i>MenuScene, GameScene</i> 등.</li>
    <li><b>Player/Enemy/Bullet</b>: 입력/AI/투사체 로직과 충돌 반응.</li>
    <li><b>ResourceManager</b>: 이미지/사운드 캐싱·해제.</li>
    <li><b>Utils/Math</b>: 충돌/거리/보간/타이머 등.</li>
  </ul>

  <!-- 리소스 관리 -->
  <h3 id="full-res">D. 리소스 관리</h3>
  <ul>
    <li>이미지: <code>LoadImage/LoadBitmap</code> → <code>HBITMAP</code> 캐싱.</li>
    <li>사운드: 효과음 즉시 재생, BGM 루프.</li>
    <li>해제: <code>DeleteObject</code>, <code>PlaySound(NULL,...)</code>.</li>
    <li>의존 역전: 오브젝트는 매니저에서 핸들만 참조.</li>
  </ul>

  <!-- 디자인 패턴 -->
  <h3 id="full-patterns">E. 디자인 패턴</h3>
  <ul>
    <li>싱글톤(Manager), 상태(Scene), 프로토타입(+풀링 후보).</li>
    <li>옵저버/팩토리는 확장 가능.</li>
  </ul>

  <!-- 충돌/수학 유틸 -->
  <h3 id="full-collision">F. 충돌 &amp; 수학 유틸</h3>
  <ul>
    <li>AABB 기본 + 일부 원형 판정, 활성 객체만 검사, 삭제 마킹 → 프레임 말 정리.</li>
    <li><code>Vector2</code>, <code>Distance/Clamp/Lerp</code>, <code>QueryPerformanceCounter</code> 기반 <code>deltaTime</code>.</li>
  </ul>

  <!-- 씬 관리 -->
  <h3 id="full-scenes">G. 씬 관리</h3>
  <ol>
    <li><code>ChangeScene</code>: <code>OnExit</code> → 삭제 → 새 씬 생성 → <code>OnEnter</code>.</li>
    <li>루프: <code>Update/Render</code> 위임, 필요 시 Sleep으로 FPS 안정화.</li>
    <li>연속 전환 방지/스택형 Pause는 확장 포인트.</li>
  </ol>

  <!-- 실행 상세 -->
  <h3 id="full-run">H. 빌드 &amp; 실행 (상세)</h3>
  <ol>
    <li>저장소 클론/ZIP 다운로드</li>
  </ol>
  <pre><code>bash
git clone https://github.com/yourusername/WinAPI_Isaac_Project.git
</code></pre>
  <ol start="2">
    <li>VS에서 <code>WinAPI_Isaac_Project.sln</code> 열기 → Win32(x86) Debug 또는 Release</li>
    <li>Build → F5 실행, 종료 시 누수 경고 확인</li>
  </ol>

  <p><a href="#top">⬆ Back to top</a></p>
</details>

<hr/>

<!-- Custom insights for this project -->
<h2 id="insights">12) 🌱 느낀점 &amp; 설계 의도</h2>
<ul>
  <li><b>OS 레벨의 흐름 이해</b>: 엔진 없이 Win32 <b>메시지 루프</b>와 윈도우 라이프사이클을 직접 다루며, 입력/타이밍/렌더링 파이프라인의 상호작용을 몸으로 익혔습니다.</li>
  <li><b>프레임 독립 업데이트</b>: <code>QueryPerformanceCounter</code>로 <b>deltaTime</b>을 계산해 PC 스펙과 무관한 속도를 유지했습니다. 타이머/슬립 값을 조절하며 FPS 안정화 전략을 실험했습니다.</li>
  <li><b>자원 수명주기와 누수 방지</b>: <code>HBITMAP/HDC</code>·사운드의 생성/해제 타이밍을 명확히 정의하고, <b>일괄 해제 규칙</b>을 마련해 GDI/메모리 누수를 예방했습니다.</li>
  <li><b>상태 기반 구조의 장점</b>: <code>Scene</code> 추상 + <code>SceneManager</code>로 <b>상태 패턴</b>을 적용해 메뉴→플레이→결과 전환을 간결하게 유지했고, 신규 씬 추가 비용을 낮췄습니다.</li>
  <li><b>충돌 처리의 현실과 타협</b>: AABB 중심으로 단순/빠른 충돌을 구현하고, <b>삭제 마킹</b> 후 정리하는 흐름으로 안정성을 확보했습니다. </li>
</ul>
<p><a href="#top">⬆ Back to top</a></p>

<hr/>

<!-- Credits -->
<h2 id="credits">13) 👏 크레딧</h2>
<p>
  Author: 서재승 (Seo Jae Seung)<br/>
  Email: <a href="mailto:seojaeseung9@gmail.com">seojaeseung9@gmail.com</a><br/>
  Blog: <a href="https://seungcoding.tistory.com/" target="_blank" rel="noreferrer">https://seungcoding.tistory.com/</a><br/>
  GitHub: <a href="https://github.com/jaeseung9" target="_blank" rel="noreferrer">https://github.com/jaeseung9</a>
</p>
<p><a href="#top">⬆ Back to top</a></p>
