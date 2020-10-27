#include "get_next_line.h"

static int			find_newline_index(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i); // 개행문자를 만났을 경우 그 위치의 인덱스를 찾는 함수.
		i++;
	}
	return (-1);
}

static int			store_split(char **store, char **line, int index)
{
	char			*tmp;

	if (index >= 0)
	{
		(*store)[index] = '\0';
		if (!(*line = ft_strdup(*store))) // 라인에 담아주는 것을 이프문으로 한 이유는 방어하기 위해서?? 
			return (-1);
		tmp = ft_strdup(*store + index + 1); // 개행전까지 라인에 담아주었기  때문에 그 다음 주소값을 다시 정적변수에 담아주기 위해 템프에 듀플
		free(*store); // 프리프리 이니스프리~
		*store = tmp; // 담아줌
		return (1);
	}
	else
	{
		(*store)[ft_strlen(*store)] = '\0'; // 개행이 없을경우에는 이렇게  하는 것 같은데 굳이 널값을 넣어주는 이유는? 잘 모르겠음. 어차피 개행이 없으면 
//	   	문자열끝까지이기 때문에 널값으로 끝나있지 않나?? 이것도 그냥 혹시모를 상황에 대비한 방어장치??
		if (!(*line = ft_strdup(*store))) // 위와 같은 이유라 생각함.
			return (-1);
		free(*store); // 프리프리 이니스프리~
		*store = NULL; // EOF를 만난후 프리한이후 NULL을 넣어줘야 테스트기를 
//      예쁘게 통과한다는 사실은 알지만 이걸 왜 하는지는 아직 정확하게 이해하지 못함.
		return (0);
	}
	return (-1);
}

int					get_next_line(int fd, char **line)
{
	static char		*store[OPEN_MAX];
	char			*buffer;
	char			*temp;
	int				read_bytes;
	int				newline_index;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1); // fd는 0 ~ OPEN_MAX 까지라서 0보다 작거나 OPEN_MAX보다 큰건 오류,
//      라인이 할당 안되어있는 경우도 오류, 버퍼사이즈가 1보다 작은 경우는 당연히 오류(읽을수가 없으니까)
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1); // 스택에 할당하지 않고 힙에 할당한 이유..? : 
//      리드를 하지 않을경우가 있는데 스택으로 할당할 경우에는 사용하지 않아서 낭비가 되나..?
//      음.. 잘모르겠음
	store[fd] = store[fd] == NULL ? ft_strdup("") : store[fd]; // 스태틱변수에 아무것도 
//  담겨 있지 않은 경우에 빈문자열을 듀플해줘야 문제가 안생긴다고 알게되긴 했는데 정확히 왜 하는지는
//  아직 잘 모르겠음. 
	while ((newline_index = find_newline_index(store[fd])) < 0 &&
			(read_bytes = read(fd, buffer, BUFFER_SIZE)) > 0) // 개행문자가 없을경우에만
//          리드를 함. 개행 문자가 있을때도 리드를 해버리면 와일문이 안돌아버려서 문제가 생기지 않을까?
//          하는 생각이 들긴함 그래서 리드를 두번째조건에 넣어서 첫조건이 실패할 경우 안돌게 한 것 같음.
	{
		buffer[read_bytes] = '\0'; //리드한 문자 끝에 널값을 넣어서 문자열을 만들어줌
		temp = ft_strjoin(store[fd], buffer); //문자열로 만들어주었기 때문에 쪼인을
//      사용할 수 있음
		if (store[fd])        // 음.. 이것도 이프문으로 하는 이유는 방어장치인가?? 
//      아니면 원래 이렇게 하는게 좋은건가.. 아니면 크게 상관은 없지만 이렇게 이프문으로 방어해놓는게
//      좋은습관인걸까~? 
			free(store[fd]);
		store[fd] = temp;
	}
	if (read_bytes < 0) // 리드함수가 -1을 반환하면 오류니까 -1반환
		return (-1);
	if (buffer) // 버퍼까지 프리프리 이니스프리
		free(buffer);
	return (store_split(&store[fd], line, newline_index)); // 리턴으로 다음함수로
//  넘겨버리는거 러쉬때도 봤는데 쓸 생각을 난 하지 못했음. 킹받
}

#include "get_next_line.h"

static int	proc_remain(char **line, char **store, char *tmp_ptr)
{
	char *tmp;

	if (tmp_ptr) // tmp_ptr의 주소가 존재한다는 말은 개행문자가 있는 주소값을 담고 있다는 의미
	{
		*line = ft_strndup(*store, tmp_ptr - *store); // 개행주소값에서 스태틱변수 주소값을
 //     빼주면 dup해야할 사이즈가 나옴.
		tmp = ft_strndup(tmp_ptr + 1, ft_strlen(tmp_ptr + 1)); // tmp에 개행다음 남은것들
 //     전부 넣어줌
		free(*store);
		*store = tmp; // 스태틱변수에 다시 담아넣어줌
		return (_SUC_READ);
	}
	if (*store) // 개행을 다 자른 후 널문자로 종료되는 문자열이 남아 있을경우를 생각
	{
		*line = *store; // 라인에 담아주고
		*store = NULL; // 스태틱변수는 널포인터를 가리키게한 후 끝.
	}
	else // 개행을 다 자르고 종료되었을 경우
		*line = ft_strndup("", 1); // 라인에는 빈문자열만 넣어 놓는다.
	return (_EOF);
}

int		get_next_line(int fd, char **line)
{
	int			byte; // read의 반환값 담을 변수
	char		buf[BUFFER_SIZE + 1]; // read한 내용 담을 변수
	char		*tmp_ptr; // 템프
	static char	*store[OPEN_MAX]; // 리드한것들을 담아놓을 스태틱변수

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (_ERROR);
	if (!store[fd])
		store[fd] = ft_strndup("", 1);
	while (!(tmp_ptr = ft_strchr(store[fd],'\n'))
	&& (byte = read(fd, buf, BUFFER_SIZE)) > 0) // 개행을 만나지 않을경우에만
 // 리드를 하면서 와일문 돌림
	{
		buf[byte] = 0; //읽은 것들 끝에 널문자를 넣어 문자열로 만들어줌.
		if (store[fd])
			tmp_ptr = ft_strjoin(store[fd], buf);
		else
			tmp_ptr = ft_strndup(buf, byte);
		if (store[fd])
			free(store[fd]);
		store[fd] = tmp_ptr;
	}

	if (byte < 0)
		return (_ERROR);
	return (proc_remain(line, &store[fd], tmp_ptr));
}

#include "get_next_line.h"

int		make_keep(int rd_buff, char **keep, char *temp, char **line)
{
	char		*c;

	if ((c = ft_strchr(*keep, '\n'))) // 스태틱변수에서 개행을 찾은 경우
	{
		*c = 0;
		*line = ft_strdup(*keep);
		temp = *keep;
		*keep = ft_strdup(ft_strchr(*keep, 0) + 1); // 널문자를 찾은 후 그 다음 주소로 다시 스태틱 변수를 채워줌
		free(temp); // 라인에 dup를 이용해서 담아주고 스태틱변수에는 새로운 주소를 담았기 때문에 새로운 주소를 담기전의 스태틱변수 주소는 프리를 해주어야함 그래서 프리프리 이니스프리
		return (1);
	}
	else if (rd_buff == 0) // rd_buff가 0일때도 개행이 있는 경우는 위의 이프문에서 걸러지기 때문에 개행이 없고 rd_buff가 0일때 이 조건문으로 들어오게된다. 결국 개행 없는 널로 종료되는 문자열만 남았을 경우 들어오게 된다.
	{
		*line = *keep; // 담아주고
		*keep = ft_strdup(""); // 주소값 변경해주고
		free(*keep); // 프리를 해준다.
		*keep = NULL; // 스태틱 변수는 널포인터를 가리키게 한다.
		return (0);
	}
	return (2); // 그냥 의미없는 리턴. 어차피 위의 두 조건에서만 걸리기 때문에
}

void	chk_rd_buff(char **keep, char *temp, char *buff)
{
	*keep = ft_strjoin(temp, buff);
	free(temp);
}

int		get_next_line(int fd, char **line)
{
	static char *keep;
	char		*temp;
	char		buff[BUFFER_SIZE + 1];
	int			rd_buff;
	int			res;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > 10240)
		return (-1); // 이제는 익숙한 예외처리
	while ((rd_buff = read(fd, buff, BUFFER_SIZE)) >= 0) // 와일문에서는 읽고 안에서 개행 만났을 경우는 rd_buff가 0일때도 와일문을 계속 돌게해서 와일문 안에서 처리
	{
		keep = keep == NULL ? ft_strdup("") : keep; // 스태틱 변수가 널포인터를 가리키고 있으면 빈문자열을 넣어주고 아니면 그냥 그대로
		buff[rd_buff] = 0;
		temp = keep;
		if (rd_buff != 0) // 리드한 것이 있을때만
			chk_rd_buff(&keep, temp, buff); // 스태틱변수에 strjoin으로 읽은 것 넣어줌
		if ((res = make_keep(rd_buff, &keep, temp, line)) == 1) // 여기가 라인에 넣어주는 역할을 하는 곳.
			return (1);
		else if (res == 0) // res가 0이라는 의미는 파일도 다 읽었고 라인에 담아줄 것도 다 담았을 경우를 의미한다
			return (0);
	}
	if (rd_buff < 0)
		return (-1);
	return (0);
}
