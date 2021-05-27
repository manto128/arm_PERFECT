const int inp_data [] ={
83, 85, 83, 81, 77, 66, 56, 48, 37, 28, 27, 25, 24, 24, 24, 24, 25, 25, 24, 22, 18, 14, 11, 10, 6, 5, 5, 5, 6, 9, 19, 32, 46, 56, 64, 75, 85, 91, 95, 96, 95, 96, 95, 93, 88, 80, 74, 69, 59, 47, 37, 31, 27, 25, 25, 26, 28, 29, 29, 29, 30, 27, 26, 24, 
59, 47, 37, 31, 27, 25, 25, 26, 28, 29, 29, 29, 30, 27, 26, 24, 81, 84, 82, 78, 72, 63, 53, 46, 35, 25, 21, 17, 17, 17, 16, 19, 20, 21, 20, 18, 15, 11, 10, 8, 6, 4, 5, 5, 7, 12, 22, 35, 47, 58, 67, 74, 79, 82, 88, 92, 94, 97, 96, 95, 89, 79, 73, 70, 
47, 58, 67, 74, 79, 82, 88, 92, 94, 97, 96, 95, 89, 79, 73, 70, 62, 52, 42, 34, 28, 25, 24, 23, 26, 28, 28, 28, 26, 25, 24, 22, 74, 77, 77, 73, 64, 56, 47, 39, 29, 19, 14, 12, 11, 10, 12, 12, 13, 15, 15, 13, 11, 9, 7, 6, 5, 4, 4, 5, 8, 15, 24, 36, 
13, 15, 15, 13, 11, 9, 7, 6, 5, 4, 4, 5, 8, 15, 24, 36, 48, 60, 71, 76, 77, 78, 86, 90, 94, 98, 99, 98, 91, 80, 74, 72, 66, 57, 49, 40, 31, 26, 21, 22, 24, 26, 28, 28, 27, 25, 23, 21, 63, 67, 67, 63, 57, 49, 39, 30, 20, 12, 8, 7, 7, 7, 5, 7, 
63, 67, 67, 63, 57, 49, 39, 30, 20, 12, 8, 7, 7, 7, 5, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 4, 4, 4, 8, 17, 26, 36, 48, 60, 69, 73, 73, 75, 87, 92, 95, 97, 100, 99, 92, 81, 77, 75, 69, 63, 53, 44, 34, 26, 21, 21, 22, 24, 25, 26, 25, 23, 21, 19, 
69, 63, 53, 44, 34, 26, 21, 21, 22, 24, 25, 26, 25, 23, 21, 19, 52, 59, 72, 75, 81, 74, 68, 44, 15, 7, 5, 4, 5, 4, 5, 5, 5, 6, 6, 6, 6, 5, 5, 4, 5, 3, 3, 4, 8, 19, 29, 39, 48, 58, 63, 66, 68, 71, 85, 92, 95, 98, 99, 97, 93, 85, 81, 78, 
48, 58, 63, 66, 68, 71, 85, 92, 95, 98, 99, 97, 93, 85, 81, 78, 72, 65, 57, 48, 37, 27, 20, 18, 18, 20, 22, 22, 21, 19, 18, 16, 60, 108, 136, 126, 105, 108, 139, 146, 96, 34, 6, 5, 4, 3, 3, 3, 4, 4, 4, 5, 5, 5, 4, 4, 3, 3, 3, 2, 6, 18, 33, 42, 
4, 4, 4, 5, 5, 5, 4, 4, 3, 3, 3, 2, 6, 18, 33, 42, 50, 58, 61, 61, 62, 67, 81, 90, 94, 97, 97, 95, 94, 88, 83, 77, 70, 65, 59, 50, 37, 27, 19, 21, 30, 38, 42, 38, 23, 14, 13, 12, 72, 96, 76, 143, 154, 161, 169, 126, 140, 82, 10, 5, 4, 3, 3, 3, 
72, 96, 76, 143, 154, 161, 169, 126, 140, 82, 10, 5, 4, 3, 3, 3, 3, 3, 4, 5, 5, 6, 4, 4, 3, 3, 3, 3, 4, 13, 29, 41, 50, 57, 59, 58, 59, 64, 75, 83, 90, 93, 93, 92, 89, 83, 78, 72, 66, 62, 57, 49, 35, 25, 45, 89, 90, 80, 89, 112, 99, 33, 9, 9, 
66, 62, 57, 49, 35, 25, 45, 89, 90, 80, 89, 112, 99, 33, 9, 9, 87, 129, 100, 97, 141, 151, 132, 135, 152, 98, 23, 6, 6, 5, 4, 5, 5, 6, 7, 8, 8, 9, 7, 7, 7, 4, 4, 4, 5, 9, 22, 35, 44, 51, 54, 54, 56, 60, 68, 75, 81, 87, 88, 84, 78, 73, 68, 64, 
44, 51, 54, 54, 56, 60, 68, 75, 81, 87, 88, 84, 78, 73, 68, 64, 59, 57, 53, 44, 31, 28, 57, 76, 122, 135, 146, 138, 115, 78, 14, 6, 116, 132, 146, 114, 105, 125, 152, 164, 144, 131, 31, 13, 13, 11, 10, 11, 13, 13, 14, 16, 18, 19, 20, 20, 20, 18, 17, 18, 17, 19, 25, 34, 
13, 13, 14, 16, 18, 19, 20, 20, 20, 18, 17, 18, 17, 19, 25, 34, 42, 49, 54, 57, 59, 61, 65, 73, 80, 84, 86, 80, 73, 68, 65, 61, 56, 55, 51, 41, 29, 43, 76, 58, 82, 146, 149, 92, 95, 117, 36, 6, 117, 165, 190, 187, 145, 180, 219, 223, 209, 133, 29, 27, 27, 26, 26, 27, 
117, 165, 190, 187, 145, 180, 219, 223, 209, 133, 29, 27, 27, 26, 26, 27, 28, 29, 32, 35, 37, 39, 41, 42, 42, 43, 42, 41, 40, 40, 43, 47, 51, 57, 61, 64, 65, 67, 71, 79, 85, 88, 86, 82, 76, 68, 68, 77, 81, 75, 56, 39, 31, 53, 103, 129, 119, 126, 141, 161, 160, 172, 73, 6, 
81, 75, 56, 39, 31, 53, 103, 129, 119, 126, 141, 161, 160, 172, 73, 6, 112, 112, 121, 148, 158, 179, 171, 164, 147, 85, 46, 45, 44, 43, 43, 43, 44, 46, 49, 52, 55, 58, 60, 62, 62, 62, 62, 62, 61, 60, 61, 62, 64, 67, 70, 72, 72, 77, 85, 89, 93, 94, 91, 94, 116, 99, 87, 96, 
64, 67, 70, 72, 72, 77, 85, 89, 93, 94, 91, 94, 116, 99, 87, 96, 122, 141, 117, 61, 38, 53, 103, 126, 143, 148, 172, 185, 199, 188, 66, 9, 127, 106, 108, 111, 111, 121, 126, 145, 142, 89, 63, 63, 61, 59, 58, 58, 59, 60, 62, 65, 69, 73, 75, 76, 77, 78, 78, 77, 76, 75, 75, 75, 
59, 60, 62, 65, 69, 73, 75, 76, 77, 78, 78, 77, 76, 75, 75, 75, 75, 75, 76, 78, 80, 88, 97, 100, 102, 102, 95, 77, 65, 91, 115, 114, 140, 113, 118, 105, 56, 52, 62, 72, 89, 118, 120, 117, 124, 115, 48, 19, 127, 89, 101, 99, 115, 155, 177, 143, 119, 92, 84, 84, 82, 80, 78, 77, 
127, 89, 101, 99, 115, 155, 177, 143, 119, 92, 84, 84, 82, 80, 78, 77, 79, 80, 82, 84, 87, 90, 92, 93, 96, 96, 96, 95, 94, 93, 92, 92, 91, 91, 91, 91, 94, 103, 110, 112, 113, 114, 101, 104, 85, 71, 132, 152, 142, 90, 119, 126, 78, 71, 93, 116, 107, 113, 105, 116, 117, 116, 72, 43, 
142, 90, 119, 126, 78, 71, 93, 116, 107, 113, 105, 116, 117, 116, 72, 43, 147, 106, 115, 116, 122, 139, 194, 163, 121, 109, 103, 104, 103, 101, 100, 99, 100, 101, 102, 104, 106, 109, 111, 113, 115, 115, 116, 115, 114, 115, 114, 112, 112, 112, 109, 110, 114, 122, 125, 127, 128, 129, 109, 123, 142, 136, 105, 134, 
112, 112, 109, 110, 114, 122, 125, 127, 128, 129, 109, 123, 142, 136, 105, 134, 148, 170, 162, 172, 102, 81, 95, 104, 132, 150, 121, 93, 108, 121, 102, 70, 159, 145, 168, 134, 120, 134, 189, 168, 130, 139, 121, 121, 122, 120, 119, 117, 118, 119, 119, 120, 123, 125, 127, 128, 130, 131, 133, 133, 124, 101, 84, 82, 
118, 119, 119, 120, 123, 125, 127, 128, 130, 131, 133, 133, 124, 101, 84, 82, 92, 115, 127, 128, 131, 138, 139, 140, 141, 143, 95, 98, 134, 140, 120, 145, 157, 178, 194, 157, 107, 100, 105, 109, 132, 153, 143, 124, 133, 166, 134, 86, 119, 149, 190, 149, 129, 144, 174, 175, 156, 189, 136, 133, 136, 134, 133, 133, 
119, 149, 190, 149, 129, 144, 174, 175, 156, 189, 136, 133, 136, 134, 133, 133, 133, 134, 134, 134, 135, 137, 137, 138, 139, 141, 142, 117, 99, 63, 66, 78, 81, 108, 129, 135, 141, 145, 147, 148, 150, 153, 104, 86, 95, 95, 102, 113, 115, 104, 94, 101, 106, 128, 117, 116, 147, 188, 172, 159, 174, 195, 140, 96, 
115, 104, 94, 101, 106, 128, 117, 116, 147, 188, 172, 159, 174, 195, 140, 96, 107, 128, 192, 213, 179, 192, 196, 187, 190, 206, 143, 140, 143, 144, 144, 143, 143, 144, 144, 144, 144, 145, 145, 144, 146, 149, 130, 58, 48, 77, 91, 97, 102, 83, 87, 131, 146, 147, 150, 152, 156, 148, 100, 102, 116, 136, 116, 114, 
102, 83, 87, 131, 146, 147, 150, 152, 156, 148, 100, 102, 116, 136, 116, 114, 127, 131, 119, 126, 126, 179, 147, 147, 195, 199, 183, 191, 206, 204, 174, 137, 117, 117, 138, 195, 212, 212, 216, 198, 195, 202, 145, 145, 148, 150, 150, 150, 150, 148, 149, 150, 150, 149, 148, 148, 149, 150, 114, 66, 34, 55, 118, 140, 
150, 148, 149, 150, 150, 149, 148, 148, 149, 150, 114, 66, 34, 55, 118, 140, 96, 53, 97, 133, 143, 148, 151, 154, 157, 107, 80, 115, 117, 116, 127, 152, 136, 119, 128, 122, 149, 184, 157, 167, 217, 214, 200, 209, 215, 205, 188, 157, 115, 120, 112, 135, 206, 216, 225, 206, 194, 191, 143, 145, 148, 150, 150, 151, 
115, 120, 112, 135, 206, 216, 225, 206, 194, 191, 143, 145, 148, 150, 150, 151, 152, 150, 150, 151, 151, 149, 147, 146, 148, 147, 112, 96, 96, 90, 116, 121, 123, 113, 122, 159, 146, 144, 148, 154, 135, 80, 87, 123, 142, 131, 177, 199, 181, 150, 145, 125, 163, 173, 164, 169, 205, 227, 206, 198, 209, 196, 182, 169, 
181, 150, 145, 125, 163, 173, 164, 169, 205, 227, 206, 198, 209, 196, 182, 169, 122, 131, 121, 100, 178, 215, 213, 200, 190, 183, 139, 143, 146, 146, 147, 147, 147, 147, 147, 147, 146, 145, 142, 141, 143, 146, 101, 98, 129, 142, 127, 151, 177, 174, 182, 188, 148, 145, 145, 147, 92, 65, 121, 172, 154, 148, 188, 205, 
177, 174, 182, 188, 148, 145, 145, 147, 92, 65, 121, 172, 154, 148, 188, 205, 178, 161, 151, 148, 152, 148, 158, 156, 190, 219, 190, 179, 203, 196, 172, 167, 120, 126, 144, 109, 166, 207, 196, 187, 170, 152, 139, 144, 146, 146, 146, 145, 145, 145, 146, 145, 142, 141, 140, 142, 147, 137, 87, 73, 68, 70, 96, 116, 
145, 145, 146, 145, 142, 141, 140, 142, 147, 137, 87, 73, 68, 70, 96, 116, 107, 105, 104, 104, 143, 149, 150, 137, 64, 81, 134, 191, 166, 146, 162, 201, 187, 177, 169, 157, 144, 133, 144, 139, 185, 209, 170, 173, 199, 205, 179, 141, 133, 121, 145, 113, 107, 200, 196, 184, 158, 148, 148, 151, 151, 151, 151, 150, 
133, 121, 145, 113, 107, 200, 196, 184, 158, 148, 148, 151, 151, 151, 151, 150, 149, 149, 149, 148, 147, 147, 150, 154, 144, 95, 76, 80, 84, 72, 67, 74, 90, 101, 102, 108, 149, 158, 158, 134, 64, 81, 141, 201, 195, 157, 162, 218, 207, 180, 189, 189, 146, 104, 138, 162, 192, 212, 171, 168, 187, 204, 173, 103, 
207, 180, 189, 189, 146, 104, 138, 162, 192, 212, 171, 168, 187, 204, 173, 103, 116, 108, 124, 130, 111, 195, 213, 169, 149, 153, 158, 159, 157, 159, 159, 157, 156, 156, 155, 153, 154, 156, 163, 145, 95, 65, 76, 91, 110, 111, 100, 122, 152, 127, 111, 102, 143, 166, 168, 136, 73, 84, 158, 194, 211, 173, 171, 222, 
152, 127, 111, 102, 143, 166, 168, 136, 73, 84, 158, 194, 211, 173, 171, 222, 209, 192, 213, 197, 119, 75, 121, 152, 183, 204, 165, 161, 173, 198, 157, 103, 92, 77, 105, 115, 118, 201, 214, 166, 153, 156, 160, 161, 162, 163, 163, 160, 158, 157, 156, 155, 157, 162, 159, 95, 62, 76, 85, 126, 161, 133, 125, 142, 
158, 157, 156, 155, 157, 162, 159, 95, 62, 76, 85, 126, 161, 133, 125, 142, 170, 147, 124, 119, 139, 170, 172, 124, 83, 107, 169, 184, 215, 200, 203, 221, 222, 210, 210, 188, 122, 70, 114, 146, 186, 190, 151, 147, 165, 193, 165, 106, 104, 68, 81, 99, 101, 194, 194, 151, 152, 154, 154, 156, 158, 159, 160, 155, 
104, 68, 81, 99, 101, 194, 194, 151, 152, 154, 154, 156, 158, 159, 160, 155, 151, 151, 148, 148, 151, 155, 124, 79, 93, 80, 78, 174, 174, 145, 139, 147, 167, 142, 117, 138, 166, 157, 157, 108, 76, 110, 172, 196, 209, 206, 211, 213, 202, 203, 213, 168, 83, 82, 124, 145, 182, 183, 149, 153, 178, 195, 160, 80, 
202, 203, 213, 168, 83, 82, 124, 145, 182, 183, 149, 153, 178, 195, 160, 80, 98, 78, 77, 87, 93, 168, 162, 142, 148, 150, 149, 150, 152, 153, 155, 151, 144, 142, 140, 141, 144, 141, 85, 90, 104, 129, 115, 173, 170, 166, 163, 175, 194, 161, 157, 166, 173, 135, 131, 67, 32, 129, 178, 203, 201, 195, 203, 199, 
194, 161, 157, 166, 173, 135, 131, 67, 32, 129, 178, 203, 201, 195, 203, 199, 196, 202, 207, 138, 73, 96, 143, 157, 156, 166, 164, 174, 195, 208, 170, 102, 113, 114, 94, 92, 71, 116, 154, 147, 137, 150, 153, 156, 156, 155, 157, 156, 147, 144, 144, 147, 148, 131, 70, 85, 109, 117, 158, 186, 198, 171, 163, 187, 
147, 144, 144, 147, 148, 131, 70, 85, 109, 117, 158, 186, 198, 171, 163, 187, 217, 172, 184, 165, 175, 125, 119, 55, 44, 123, 178, 197, 191, 186, 194, 192, 192, 196, 208, 110, 89, 108, 141, 156, 155, 134, 160, 175, 181, 216, 180, 119, 151, 157, 123, 96, 66, 124, 166, 159, 121, 155, 164, 168, 171, 163, 157, 146, 
151, 157, 123, 96, 66, 124, 166, 159, 121, 155, 164, 168, 171, 163, 157, 146, 163, 161, 163, 170, 162, 117, 103, 107, 101, 108, 167, 196, 214, 196, 177, 193, 218, 191, 196, 164, 171, 132, 120, 82, 56, 140, 166, 182, 187, 178, 184, 185, 177, 187, 178, 90, 115, 130, 139, 162, 164, 130, 152, 139, 148, 197, 167, 109, 
177, 187, 178, 90, 115, 130, 139, 162, 164, 130, 152, 139, 148, 197, 167, 109, 185, 182, 143, 111, 86, 149, 181, 153, 128, 162, 153, 166, 181, 162, 145, 141, 172, 162, 122, 177, 167, 109, 103, 117, 68, 113, 179, 208, 214, 198, 186, 202, 215, 199, 188, 154, 143, 125, 129, 78, 51, 150, 133, 161, 180, 177, 168, 169, 
215, 199, 188, 154, 143, 125, 129, 78, 51, 150, 133, 161, 180, 177, 168, 169, 185, 192, 149, 111, 142, 141, 130, 167, 153, 112, 131, 103, 141, 176, 160, 126, 155, 161, 166, 141, 136, 149, 157, 157, 142, 153, 130, 154, 164, 154, 124, 121, 165, 122, 89, 174, 144, 98, 80, 84, 73, 137, 165, 195, 209, 210, 194, 196, 
165, 122, 89, 174, 144, 98, 80, 84, 73, 137, 165, 195, 209, 210, 194, 196, 208, 189, 162, 138, 105, 131, 127, 72, 58, 135, 138, 139, 179, 178, 159, 174, 192, 182, 133, 113, 147, 154, 138, 163, 147, 125, 110, 84, 141, 151, 153, 130, 135, 140, 150, 154, 152, 142, 126, 153, 141, 130, 122, 135, 134, 140, 116, 104, 
135, 140, 150, 154, 152, 142, 126, 153, 141, 130, 122, 135, 134, 140, 116, 104, 158, 80, 111, 163, 131, 138, 82, 56, 102, 134, 170, 177, 174, 190, 186, 196, 203, 167, 161, 127, 116, 153, 111, 61, 71, 101, 164, 141, 187, 181, 148, 166, 176, 153, 120, 120, 164, 146, 130, 144, 142, 133, 104, 86, 141, 138, 145, 121, 
176, 153, 120, 120, 164, 146, 130, 144, 142, 133, 104, 86, 141, 138, 145, 121, 139, 121, 134, 142, 114, 121, 124, 149, 142, 125, 117, 130, 115, 100, 88, 74, 105, 55, 95, 108, 122, 140, 96, 76, 131, 127, 148, 149, 178, 172, 167, 195, 198, 167, 143, 103, 106, 129, 109, 101, 93, 109, 174, 152, 146, 141, 128, 130, 
198, 167, 143, 103, 106, 129, 109, 101, 93, 109, 174, 152, 146, 141, 128, 130, 152, 132, 127, 137, 152, 124, 112, 134, 147, 142, 109, 93, 115, 130, 132, 122, 144, 112, 140, 155, 109, 105, 118, 145, 139, 124, 109, 103, 79, 56, 52, 53, 81, 67, 87, 89, 115, 140, 89, 95, 126, 153, 147, 153, 164, 156, 179, 200, 
81, 67, 87, 89, 115, 140, 89, 95, 126, 153, 147, 153, 164, 156, 179, 200, 175, 137, 137, 105, 97, 104, 107, 143, 122, 142, 159, 140, 102, 95, 128, 132, 128, 126, 121, 135, 137, 105, 111, 132, 140, 151, 120, 106, 105, 122, 113, 125, 135, 95, 130, 136, 120, 115, 117, 134, 140, 131, 106, 79, 93, 70, 75, 47, 
135, 95, 130, 136, 120, 115, 117, 134, 140, 131, 106, 79, 93, 70, 75, 47, 95, 93, 108, 131, 114, 124, 122, 116, 128, 169, 146, 144, 151, 180, 182, 168, 146, 118, 123, 115, 109, 98, 111, 152, 129, 130, 147, 129, 98, 97, 132, 130, 126, 125, 109, 123, 136, 99, 125, 114, 126, 131, 133, 125, 107, 121, 105, 129, 
126, 125, 109, 123, 136, 99, 125, 114, 126, 131, 133, 125, 107, 121, 105, 129, 141, 87, 102, 121, 124, 114, 107, 121, 152, 152, 94, 78, 124, 115, 113, 57, 116, 116, 131, 134, 106, 106, 127, 126, 135, 154, 149, 150, 180, 190, 167, 147, 125, 124, 113, 118, 96, 105, 120, 149, 125, 130, 167, 140, 101, 81, 121, 131, 
125, 124, 113, 118, 96, 105, 120, 149, 125, 130, 167, 140, 101, 81, 121, 131, 133, 133, 118, 131, 144, 125, 144, 107, 130, 121, 121, 120, 111, 113, 98, 77, 126, 101, 99, 120, 123, 104, 102, 121, 158, 139, 89, 89, 130, 140, 128, 81, 125, 138, 145, 119, 98, 106, 115, 129, 127, 122, 139, 162, 166, 149, 155, 147, 
125, 138, 145, 119, 98, 106, 115, 129, 127, 122, 139, 162, 166, 149, 155, 147, 120, 127, 131, 129, 82, 84, 132, 134, 121, 147, 188, 136, 97, 92, 99, 125, 140, 129, 120, 129, 132, 136, 145, 122, 147, 134, 131, 129, 106, 117, 122, 82, 151, 124, 107, 127, 120, 102, 105, 137, 164, 143, 110, 131, 135, 129, 127, 102 }; 
