#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "fs.h"

unsigned char encoding_table[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};



unsigned char check(char isi){
    if (isi >= 65 && isi <= 90) //Between A-Z
        isi -= 65;
    else if (isi >= 97 && isi <= 122)
        isi -= 97 + 26;
    else if (isi >= 48 && isi <= 57) //Between 0-9
        isi = isi - 48 + 52;
    else if (isi == 43) // +
        isi = 62;
    else if (isi == 47) // /
        isi = 63;
    return(isi);
}

int base64_encode(unsigned char in[], unsigned char out[], int len, int newline_flag, int separator){
   int index,index2,blks,left_over;

   blks = (len / 3) * 3;
   for (index=0,index2=0; index < blks; index += 3,index2 += 4) {
        out[index2] = encoding_table[in[index] >> 2];
        out[index2+1] = encoding_table[((in[index] & 0x03) << 4) + (in[index+1] >> 4)];
        out[index2+2] = encoding_table[((in[index+1] & 0x0f) << 2) + (in[index+2] >> 6)];
        out[index2+3] = encoding_table[in[index+2] & 0x3F];
        
        if (!(index2 % (separator+1)) && newline_flag) {
            out[index2+4] = '\n';
            index2++;
        }
   }
   left_over = len % 3;
   if (left_over == 1) {
      out[index2] = encoding_table[in[index] >> 2];
      out[index2+1] = encoding_table[(in[index] & 0x03) << 4];
      out[index2+2] = '=';
      out[index2+3] = '=';
      index2 += 4;
   }
   else if (left_over == 2) {
      out[index2] = encoding_table[in[index] >> 2];
      out[index2+1] = encoding_table[((in[index] & 0x03) << 4) + (in[index+1] >> 4)];
      out[index2+2] = encoding_table[(in[index+1] & 0x0F) << 2];
      out[index2+3] = '=';
      index2 += 4;
   }
   out[index2] = '\0';
   return(index2);
}


int base64_decode(unsigned char in[], unsigned char out[], int len, int newline_flag, int separator)
{
    int index,index2,blks,left_over;

    if (in[len-1] == '=')
        len--;
    if (in[len-1] == '=')
        len--;

    blks = (len / 4) * 4;
    for (index=0,index2=0; index2 < blks; index += 3,index2 += 4) {
        out[index] = (check(in[index2]) << 2) + ((check(in[index2+1]) & 0x30) >> 4);
        out[index+1] = (check(in[index2+1]) << 4) + (check(in[index2+2]) >> 2);
        out[index+2] = (check(in[index2+2]) << 6) + check(in[index2+3]);

        if (!(index2 % (separator+1)) && newline_flag) {
            out[index2+4] = '\n';
            index2++;
        }    int index,index2,blks,left_over;

    if (in[len-1] == '=')
        len--;
    if (in[len-1] == '=')
        len--;

    blks = (len / 4) * 4;
    for (index=0,index2=0; index2 < blks; index += 3,index2 += 4) {
        out[index] = (check(in[index2]) << 2) + ((check(in[index2+1]) & 0x30) >> 4);
        out[index+1] = (check(in[index2+1]) << 4) + (check(in[index2+2]) >> 2);
        out[index+2] = (check(in[index2+2]) << 6) + check(in[index2+3]);

        if (!(index2 % (separator+1)) && newline_flag) {
            out[index2+4] = '\n';
            index2++;
        }
    }
    left_over = len % 4;
    if (left_over == 2) {
        out[index] = (check(in[index2]) << 2) + ((check(in[index2+1]) & 0x30) >> 4);
        out[index+1] = (check(in[index2+1]) << 4);
        index += 2;
    }
    else if (left_over == 3) {
        out[index] = (check(in[index2]) << 2) + ((check(in[index2+1]) & 0x30) >> 4);
        out[index+1] = (check(in[index2+1]) << 4) + (check(in[index2+2]) >> 2);
        out[index+2] = check(in[index2+2]) << 6;
        index += 3;
    }
    out[index] = '\0';
    return(index);
    }
    left_over = len % 4;
    if (left_over == 2) {
        out[index] = (check(in[index2]) << 2) + ((check(in[index2+1]) & 0x30) >> 4);
        out[index+1] = (check(in[index2+1]) << 4);
        index += 2;
    }
    else if (left_over == 3) {
        out[index] = (check(in[index2]) << 2) + ((check(in[index2+1]) & 0x30) >> 4);
        out[index+1] = (check(in[index2+1]) << 4) + (check(in[index2+2]) >> 2);
        out[index+2] = check(in[index2+2]) << 6;
        index += 3;
    }
    out[index] = '\0';
    return(index);
}

int main(int argc, char *argv[]){
   //USAGE:
   //base64 file -> for eecode data
   //base64 -d file -> for decode data 
   //base64 -e file -> for encode data
   //base64 -w n file -> for encode and add newline every n characters
   //base64 -we n file -> for encode and add newline every n characters
   //base64 -wd n file -> for dencode and add newline every n characters
    if(argc==2){
        int inputfile;
        if((inputfile = open(argv[1],O_RDONLY)) < 0){
            close(inputfile);
            exit();
        }
        int buff_len;
        unsigned char output[1024],data[1024];
        while ((buff_len = read(inputfile,data,sizeof(data))) > 0);
        base64_encode(data, output, strlen((char*)data),0,76);
        printf(1,"%s\n",output);
        close(inputfile);
        exit();
   }
   else if(argc==3){
        if((strcmp(argv[1],"-d"))==0){
            int inputfile;
            if((inputfile = open(argv[2],O_RDONLY)) < 0){
            close(inputfile);
            exit();
            }
            int buff_len;
            unsigned char output[1024],data[1024];
            while ((buff_len = read(inputfile,data,sizeof(data))) > 0);
            base64_decode(data, output, strlen((char*)data),0,76);
            printf(1,"%s\n",output);
            close(inputfile);
            exit();
        }
        else if((strcmp(argv[1],"-e"))==0){
            int inputfile;
            if((inputfile = open(argv[2],O_RDONLY)) < 0){
            close(inputfile);
            exit();
            }
            int buff_len;
            unsigned char output[1024],data[1024];
            while ((buff_len = read(inputfile,data,sizeof(data))) > 0);
            base64_encode(data, output, strlen((char*)data),0,76);
            printf(1,"%s\n",output);
            close(inputfile);
            exit();  
        }
   }
    else if(argc==4){
        if((strcmp(argv[1],"-wd"))==0){
            int inputfile;
            if((inputfile = open(argv[3],O_RDONLY)) < 0){
            close(inputfile);
            exit();
            }
            int buff_len;
            unsigned char output[1024],data[1024];
            while ((buff_len = read(inputfile,data,sizeof(data))) > 0);
            int linebaru;
            linebaru = atoi(argv[2]);
            base64_decode(data, output, strlen((char*)data),1,linebaru);
            printf(1,"%s\n",output);
            close(inputfile);
            exit();
        }
    else if((strcmp(argv[1],"-we"))==0){
        int inputfile;
        if((inputfile = open(argv[3],O_RDONLY)) < 0){
            close(inputfile);
            exit();
        }
        int buff_len;
        unsigned char output[1024],data[1024];
        while ((buff_len = read(inputfile,data,sizeof(data))) > 0);
        int linebaru;
        linebaru = atoi(argv[2]);
        base64_encode(data, output, strlen((char*)data),1,linebaru);
        printf(1,"%s\n",output);
        close(inputfile);
        exit();  
      }
      else{
        int inputfile;
        if((inputfile = open(argv[3],O_RDONLY)) < 0){
            close(inputfile);
            exit();
        }
        int buff_len;
        unsigned char output[1024],data[1024];
        while ((buff_len = read(inputfile,data,sizeof(data))) > 0);
        int linebaru;
        
        linebaru = atoi(argv[2]);
        base64_encode(data, output, strlen((char*)data),1,linebaru);
        printf(1,"%s\n",output);
        close(inputfile);
        exit();
      }
   }
}
