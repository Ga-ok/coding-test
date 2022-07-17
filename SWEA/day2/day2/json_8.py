import json
import requests

key = 'bZY2BX3H8gbtRmDjqP737PQnKoD4w6lXhK9mOcMC/gDrtrvpvfEEnjfy816HKkJLoB0gtoHrCng1qoM3JmgGvQ=='

url = 'http://apis.data.go.kr/1480523/MetalMeasuringResultService/MetalService'
params ={'serviceKey' : key, 'pageNo' : '1', 'numOfRows' : '10', 'resultType' : 'json', 'date' : '20171208', 'stationcode' : '1', 'itemcode' : '90303', 'timecode' : 'RH02' }

response = requests.get(url, params=params)
dic = json.loads(response.content)

for i in dic['MetalService']['item']:

    # 날짜
    year = i['SDATE'][:4]
    month = i['SDATE'][4:6]
    day = i['SDATE'][6:8]

    hour = i['SDATE'][8:10]
    min = i['SDATE'][10:12]
    sec = i['SDATE'][12:14]

    # 대기 환경 연구소명
    station = i['STATIONCODE']
    station_dic={1:'수도권', 2:'백령도', 3:'호남권', 4:'중부권', 5:'제주권', 6:'영남권', 7:'경기권', 8:'충청권', 9:'전북권', 10:'강원권'}

    # 측정 항목 종류
    item = i['ITEMCODE']
    item_dic={'90303': '납', '90319': '칼슘'}

    # 측정 수치
    value = i['VALUE']

    # 보기 좋게 출력
    print("=======================================================================")
    print('날짜:                   ', year,'년', month, '월', day, '일', hour, '시',  min, '분', sec, '초')
    print('대기환경연구소명:         ', station_dic[station])
    print('측정항목 종류(납/칼슘):    ', item_dic[item])
    print('측정수치                 ', str(value)+' ng/m3')









