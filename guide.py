# Tạo từ điển ban đầu
diem_tong_ket = {
    'MSV1': 2.8,
    'MSV2': 3.2,
    'MSV3': 1.5,
    'MSV4': 2.9
}

# Đếm số sinh viên có điểm tổng kết trong đoạn [2.5, 3.5]
so_sinh_vien_trong_doan = sum(1 for diem in diem_tong_ket.values() if 2.5 <= diem <= 3.5)
print("Số sinh viên có điểm tổng kết trong đoạn [2.5, 3.5]:", so_sinh_vien_trong_doan)

# Bổ sung 1 sinh viên vào từ điển
diem_tong_ket['MSV5'] = 3.7

# Xóa mọi sinh viên có điểm tổng kết nhỏ hơn 2.0
sinh_vien_can_xoa = [msv for msv, diem in diem_tong_ket.items() if diem < 2.0]
for msv in sinh_vien_can_xoa:
    del diem_tong_ket[msv]

# In toàn bộ từ điển ra màn hình
print("Từ điển sau khi thao tác:")
print(diem_tong_ket)
