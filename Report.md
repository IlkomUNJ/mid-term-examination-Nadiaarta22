Computer Graphics - Mid Term Report
Name: Nadia Artamelina  
Class: A  2023
NIM : 1313623057

#Window Size Analysis
Langkah pertama yang saya lakukan adalah mencoba beberapa ukuran window untuk mencari mana yang paling sesuai dalam mendeteksi segmen.
Saya memulai dengan ukuran kecil, yaitu 3×3, lalu mencoba ukuran yang lebih besar seperti 5×5 dan 7×7. Dari percobaan yang saya lakukan, ukuran 3×3 memberikan hasil yang paling baik. Dengan ukuran ini, titik dan garis kecil bisa terdeteksi dengan jelas tanpa terlalu banyak area kosong ikut terbaca. Ketika saya mencoba window 5×5, hasilnya masih cukup baik, namun area deteksinya mulai melebar sehingga kurang presisi di bagian detail garis.Sementara untuk window 7×7, hasilnya justru terlalu luas dan kehilangan akurasi — beberapa area kosong ikut terdeteksi sebagai segmen. Dari hasil pengamatan tersebut, saya menyimpulkan bahwa window berukuran 3×3 adalah yang paling ideal untuk mendeteksi segmen kecil seperti titik atau garis pendek, karena mampu menangkap detail tanpa menimbulkan terlalu banyak noise.

#Pattern Identification
Dari hasil pemindaian, saya menemukan bahwa area yang mengandung piksel selain putih menandakan adanya segmen. Dengan kata lain, window yang tidak kosong dianggap sebagai kandidat segmen.
Untuk menyimpan pola tersebut, saya menggunakan CustomMatrix, sedangkan posisi tiap window saya simpan dengan QRect agar bisa ditampilkan di canvas dalam bentuk kotak ungu. Pendekatan sederhana ini terbukti efektif dalam mengenali garis dan titik pada gambar.

#Automated Segment Detection Algorithm

Setelah menemukan pola window yang tepat, saya mengembangkan fungsi `segmentDetection()` di file `drawingcanvas.cpp`.  
Algoritma bekerja sebagai berikut:

1. Program mengambil dari canvas menggunakan `grab().toImage()`.  
2. Loop berjalan melewati setiap posisi piksel (kecuali area tepi).  
3. Untuk setiap posisi, dibuat window 3×3 berisi nilai boolean (aktif/tidak aktif).  
4. Jika window mengandung piksel aktif, maka disimpan sebagai kandidat (`QRect`) dan divisualisasikan dengan kotak ungu (Qt::magenta) di canvas.

Link AI:
https://chatgpt.com/share/68f5f049-ead8-8011-9704-da02dd609a21
alasan saya memakai gpt adalah dari awal saya menggunakan preplexity namun limit dan down kemudian saya pindah ke gemini tetapi limit juga, jadi saya menggunakan gpt sebagai AI saya, Mohon maaf dan terimakasih pak.