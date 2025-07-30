import Data.Time

main :: IO ()
main = do 
  !startTime <- getCurrentTime
  let !result = solution
  !endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  putStrLn ("Solution: " ++ (show result))
  putStrLn ("Execution Time: " ++ (show diffTime))
  --putStrLn $ (reverse.tail.reverse) (show diffTime)

solution :: Integer
solution = sumDigits (2^1000)

sumDigits :: Integer -> Integer
sumDigits 0 = 0
sumDigits n = (n `mod` 10) + sumDigits (n `div` 10)

