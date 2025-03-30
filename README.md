Tên game: Cat Chit
Bối cảnh:
  Bạn là một con cáo đói. Bạn nhìn thấy một con thỏ và cần phải bắt lấy nó. Nhưng kẻ đi săn không chỉ có một.
Logic game:
    - Bạn điều khiển con cáo, nếu bạn bắt được con thỏ bạn thắng, còn nếu bạn bị sói bắt bạn thua (sói không bắt thỏ).
    - Khi vào game cáo ở vị trí (0,0); thỏ ở giữa màn hình; đá được tạo 1~30 viên (khoảng 26 viên) ở vị trí ngẫu nhiên; tồn tại sẵn 3 bụi cỏ có sói ở vị trí ngẫu nhiên.
    - Cáo và sói không thể đi qua đá nhưng thỏ có thể.
    - Cáo và thỏ khi vượt qua viền màn hình sẽ di chuyển sang viền đối diện.
    - Thỏ sẽ luôn chạy khỏi cáo; di chuyển ngang hoặc dọc nhưng sẽ đổi hướng liên tục (nó tính cả khoảng cách đến viền màn hình nên không thể dùng tính năng đi qua viền để bắt nó).
    - Sau mỗi 10 giây sẽ xuất hiện ngẫu nhiên 3 bụi cỏ có sói; nếu cáo đến gần bụi cỏ (theo chiều dọc hoặc ngang) sói sẽ từ bụi lao đến cáo.
    - Sói sẽ biến mất nếu nó nhảy đến vị trí của cáo hoặc đâm vào đá.
Thao tác bàn phím:
    - Tại màn hình menu khi mới mở game: nhấn ESC để thoát; nhấn Enter để vào game.
    - Tại màn hình game : nhấn phím mũi tên để di chuyển cáo (có thể đi chéo); nhấn ESC để về menu.
    - Tại màn hình thua hoặc thắng: nhấn Enter để về lại menu.
Nguồn tài liệu:
    - Cấu trúc random, cách tách file: tài liệu ví dụ game của trường.
    - Sử dụng biến deltaTime, SDLGetticks: tham khảo AI.
    - Sử dụng SDL.h, SDL_image.h; cấu trúc class; vòng lặp game: bài giảng của trường.
    - Ảnh menu: AI
    - Ảnh khi thua và thắng, sói, cáo, thỏ, cỏ, đá: google
Mức độ sử dụng AI:
  Dùng AI để sửa lỗi cú pháp và tối ưu một số lệnh.


























  Lưu ý: khi kéo thả cửa sổ game thỏ sẽ có thể sẽ chạy bất thường (đây là tính năng không phải bug)
    
