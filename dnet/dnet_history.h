#pragma once

/* dnet: история и версия; */
#define DNET_VERSION "T11.231-T14.290" /* $DVS:time$

T14.290 код dnet для xdag переписан, убрано всё лишнее, каждый поток может обрабатывать много соединений

T13.714 добавлена команда connect ip:port, закомментирован ненужный в cheatcoin код

T13.572 потоки открепляются с помощью pthread_detach, а не pthread_join; устранена
	проблема в LDuS с зависанием gc при повторном использовании потока

T13.448 исправлена ошибка, связанная с зависанием потока, читающего из сокета

T13.428 при копировании файлов введены дополнительные параметры: начальная позиция, максимальная скорость и время её применения

T13.410 имя локального хоста сохраняется в файл; информация о хостах, не проявлявших
	активности больше 2 суток, не пересылается

T13.375 в LDuS принудительно освобождается порт сервера

T13.184 теперь номер tap интерфейса может содержать до 4 байт

T13.178 исправление ошибок в gcc 6

T13.142 теперь команды на другом хосте выполняются в отдельном потоке;
	добавлена псевдокоманда repeat для повторения команд в командной строке

T13.138 в версии для LDuS добавлена возможность создания tap интерфейсов

T13.096 введена история введённых (в том числе присланных команд) и команда history для её показа

T13.093 введены fifo-мьютексы для отправки пакетов по одному соединению

T13.064 введена команда untrust, опции -d, -h команды hosts, теперь в сообщении UPDATE (каждые 30 сек)
	посылается информация только о хостах, время активности которых менялось за последние 5 мин,
	а сообщения EXCHANGE (каждые полчаса) - только о хостах, у которых данные менялись за последний час

T13.055 исправлена ошибка при копирование файла, в имени которого есть пробелы

T13.051 в ограниченном режиме разрешено выполнять команды на другом хосте и заходить на него
	(нужно для связи с андроидом и для команды copy)

T13.047 добавлено ослабленное шифрование для ускорения генерации ключей (1024 бит
	для андроида, 2048 бит для ограниченного режима)

T13.042 добавлена команда copy для копирования файлов/каталогов между хостами

T13.014 сделана программа qdnet на Qt для PC и Android

T12.999 добавлено перенаправление UDP портов; сделан обмен версиями программ между хостами

T12.994 исправлен ряд ошибок

T12.985 игнорирование большего числа сигналов в режиме демона

T12.975 изменён порядок вывода в команде hosts, сделан полный (-a) и частичный вывод

T12.965 добавлены: перенаправление TCP портов, доверенные хосты, ограниченный режим
	(для программы, запущенной без параметров)

T12.694 в LDuS убрана перезегрузка системы при обрыве соединения

T12.677 добавлена команда close для принудительного закрытия потока (stream)

T12.664 при удалённом подключении к LDuS теперь можно работать в цветном текстовом окне

T12.617 улучшен роутинг, теперь следующий хост определяется исход из пары ip:port;
	при запуске только с параметром -d добаяляются параметры по умолчанию:
	-d -s 0.0.0.0:11231 52.5.32.68:11231

T12.527 в параметрах программы можно задать команды, которые будут выполнены после её
	запуска в формате -c "команда"; теперь при обрыве туннеля с одной стороны
	его можно пересоздать с этой стороны и на другой стороне он перезапустится

T12.405 в Linux добавлена возможность создавать Ethernet-туннели между tap-интерфейсами
	на разных машинах

T12.231 теперь при работе в shell dnet не прерывается по Ctrl-C и посылает байт 3

T12.222 в LDuS сделана возможность захода в shell

T12.172 сборщик мусора теперь вызывается чаще, раз в 5 минут, но каждый поток
	уничтожается только на второй проход сборщика мусора

T12.171 для обмена сообщениями с другими узлами сети dnet теперь заводится свой
	поток для каждого соединения

T12.170 в LDuS теперь вызывается не ldus_reboot, а ldus_shutdown

T11.765 в LDuS теперь считаются только те соединения, по которым была активность в
	последние 45 секунд, если их нет 2 раза, то перезагрузка

T11.760 число соединений теперь проверяется каждые 30 сек, соединение открывается
	заново через 45 сек простоя

T11.757 добавлена команда log для пересылки логов

T11.752 размер DNET_COMMAND_MAX увеличен до 0x1000, т. е. до максимального размера
	данных в пакете, тем самым доступно выполнение больших команд,
	передаваемых через сеть

T11.736 если при двух подряд выводах информации в лог (происходят раз в 5 минут)
	не было ни одного соединения, а при предыдущем выводе были, то программа dnet
	перезагружает систему LDuS; скорее всего, нет доступа в сеть

T11.713 если в течение 1 минуты не было прочитано данных из соединения, то оно
	открывается заново; для соектов устанавливается флаг close-on-exec, тем самым
	при падении программы dnet открытые сокеты не переходят дочерним программам

T11.711 теперь в LDuS доступно API выполнения одиночной команды (в том числе удалённого;
	функция dnet_command); параллельно может выполняться до 256 команд; в конце
	выполнения команды отправляется пустой пакет и принимающая сторона посылает сигнал
	SIGCONT ожидающему потоку (чей pid указан в поле output_file->pid)

T11.665 при удалённом выполнении одиночной команды ответ посылается асинхронно
	и может иметь любую длину

T11.635 интеграция программы в систему LDuS

T11.310 в сеансе удалённого доступа автоматически устанавливается размер терминала

T11.280 улучшение сеансов удалённого доступа

T11.278 исправлена ошибка с удалённым сеансом, улучшено логирование

T11.275 во время удалённого сеанса работы в shell ввод с терминала делается
	посимвольный, отключается эхо, а также символ 10 (\n) меняется на 13 (\r)

T11.273 реализованы потоки между хостами; добавлена возможность удалённого запуска
	сеанса работы в shell

T11.267 сделан режим демона

T11.265 команды теперь можно выполнять на удалённом хосте

T11.264 добавлены пакеты типа UPDATE для быстрого обмена временами последней активности хостов,
        для каждого хоста введён параметр route - ip-адрес соединения дял достижения этого хоста

T11.262 сделана проверка на соответствие закрытого и открытого ключей

T11.261 сделано логирование, можно давать команды для system shell

T11.259 добавлены имена хостов, теперь при обмене известными хостами посылаются также и имена

T11.256 исправление ошибок, защита от падений

T11.254 работающая версия, позволяющая обмениватьcя открытыми ключами между группой
	компьютеров

T11.231	начало проекта

*/
