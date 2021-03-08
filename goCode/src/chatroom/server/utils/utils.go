package utils

import (
	"chatroom/common/message"
	"encoding/binary"
	"encoding/json"
	"fmt"
	"net"
)

//得改造成一个OOP思想的模块.....
type Transfer struct {
	Conn net.Conn
	Buf  [8096]byte //传输的缓冲区
}

//处理客户端发送过来的数据
func (this *Transfer) ReadPkg() (mes message.Message, err error) {
	//buf := make([]byte, 8096)
	fmt.Println("读取客户端发送的消息.....")
	_, err = this.Conn.Read(this.Buf[:4])
	if err != nil {
		//err = errors.New("read pkg header error")
		//fmt.Println("conn.Read() error: ", err)
		return
	}

	var pkgLen uint32
	pkgLen = binary.BigEndian.Uint32(this.Buf[0:4])
	//根据pkgLen读取数据
	n, err := this.Conn.Read(this.Buf[:pkgLen])
	if n != int(pkgLen) || err != nil {
		return
	}

	//再将读到的消息反序列化->message.Message
	err = json.Unmarshal(this.Buf[:pkgLen], &mes)
	if err != nil {
		//err = errors.New("read pkg body error")
		fmt.Println("json.Unmarshal() error: ", err)
		return
	}
	return
}

//将服务器端处理后的数据，发怂给客户端
func (this *Transfer) WritePkg(data []byte) (err error) {
	var pkgLen uint32
	pkgLen = uint32(len(data))
	//var buf [4]byte //开辟4int8长度的数组/切片
	//将pkgLen转换为uint32位的大端，网络上跑的都是大端数据
	binary.BigEndian.PutUint32(this.Buf[0:4], pkgLen)
	//发送长度
	n, err := this.Conn.Write(this.Buf[:4])
	if n != 4 || err != nil {
		fmt.Println("conn.Write error: ", err)
		return
	}

	//发送data
	n, err = this.Conn.Write(data)
	if n != int(pkgLen) || err != nil {
		fmt.Println("data write error: ", err)
		return
	}
	return

}
