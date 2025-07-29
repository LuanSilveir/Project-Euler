import Data.Time

main :: IO ()
main = do 
  !startTime <- getCurrentTime
  let !result = solution
  !endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  --putStrLn ("Solution: " ++ (show result))
  --putStrLn ("Execution Time: " ++ (show diffTime))
  putStrLn $ (reverse.tail.reverse) (show diffTime)

solution :: Int 
solution = sum $ map sundayStarts [1901..2000]

months' :: [Int]
months' = [31,28,31,30,31,30,31,31,30,31,30,31]

begOfMonth :: Int -> Int -> Int
begOfMonth _    1 = 1
begOfMonth year 3 = if leapYear year then 61 else 60
begOfMonth year n = begOfMonth year (n-1) + months' !! (n-2)

dayOfYear :: Int -> Int -> Int
dayOfYear s day = (((day-1) `mod` 7) + s) `mod` 7  

leapYear :: Int -> Bool
leapYear year =  (year `mod` 4 == 0) && (year `mod` 100 /= 0 || year `mod` 400 == 0)

startDayOfYear :: Int -> Int
startDayOfYear 1900 = 1
startDayOfYear year = (starts !! (year - 1900 - 1) + c) `mod` 7
  where c = if leapYear (year-1) then 2 else 1

starts :: [Int]
starts = map startDayOfYear [1900..2000]

firstDayOfMonths :: Int -> [Int]
firstDayOfMonths year = (map (dayOfYear (startDayOfYear year)) (map (begOfMonth year) [1..12]))

countSundays :: [Int] -> Int
countSundays xs = length (filter (==0) xs)

sundayStarts :: Int -> Int
sundayStarts year = countSundays $ firstDayOfMonths year
